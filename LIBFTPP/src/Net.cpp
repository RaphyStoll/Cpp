// File: src/Net.cpp
#include "../include/Net.hpp"

#include <unistd.h>     // close
#include <fcntl.h>      // fcntl
#include <cerrno>       // errno
#include <cstring>      // memset

#include <netinet/tcp.h> // TCP_NODELAY
#include <arpa/inet.h>   // inet_ntop
#include <netdb.h>       // getnameinfo (optionnel mais pratique)

namespace libftpp {
namespace net {

bool set_non_blocking(int fd) {
    if (fd < 0) {
        errno = EBADF;
        return false;
    }
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
        return false;
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
        return false;
    return true;
}

bool set_reuseaddr(int fd) {
    if (fd < 0) {
        errno = EBADF;
        return false;
    }
    int yes = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
        return false;
    return true;
}

bool set_nodelay(int fd) {
    if (fd < 0) {
        errno = EBADF;
        return false;
    }
    int yes = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &yes, sizeof(yes)) == -1)
        return false;
    return true;
}

static std::string ipv4_to_string(const struct sockaddr_in* in, bool with_port) {
    char buf[INET_ADDRSTRLEN];
    const char* p = inet_ntop(AF_INET, &in->sin_addr, buf, sizeof(buf));
    if (!p)
        return std::string();

    if (!with_port)
        return std::string(buf);

    unsigned short port = ntohs(in->sin_port);
    std::string s(buf);
    s += ":";
    // C++98: pas std::to_string
    char pbuf[16];
    std::snprintf(pbuf, sizeof(pbuf), "%u", (unsigned int)port);
    s += pbuf;
    return s;
}

static std::string ipv6_to_string(const struct sockaddr_in6* in6, bool with_port) {
    char buf[INET6_ADDRSTRLEN];
    const char* p = inet_ntop(AF_INET6, &in6->sin6_addr, buf, sizeof(buf));
    if (!p)
        return std::string();

    if (!with_port)
        return std::string(buf);

    unsigned short port = ntohs(in6->sin6_port);
    std::string s = "[";
    s += buf;
    s += "]:";
    char pbuf[16];
    std::snprintf(pbuf, sizeof(pbuf), "%u", (unsigned int)port);
    s += pbuf;
    return s;
}

std::string sockaddr_to_string(const struct sockaddr* sa, socklen_t salen, bool with_port) {
    if (!sa || salen == 0)
        return std::string();

    // Option 1: getnameinfo (gère IPv4/IPv6 proprement)
    // Si tu préfères éviter getnameinfo, tu peux commenter ce bloc et utiliser inet_ntop.
    {
        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];
        int flags = NI_NUMERICHOST | NI_NUMERICSERV;
        int rc = getnameinfo(sa, salen, host, sizeof(host), serv, sizeof(serv), flags);
        if (rc == 0) {
            if (!with_port)
                return std::string(host);

            // Format IPv6 avec crochets si besoin
            if (sa->sa_family == AF_INET6) {
                std::string s = "[";
                s += host;
                s += "]:";
                s += serv;
                return s;
            }
            std::string s(host);
            s += ":";
            s += serv;
            return s;
        }
        // sinon on fallback inet_ntop ci-dessous
    }

    // Fallback inet_ntop
    if (sa->sa_family == AF_INET) {
        const struct sockaddr_in* in = (const struct sockaddr_in*)sa;
        return ipv4_to_string(in, with_port);
    }
    if (sa->sa_family == AF_INET6) {
        const struct sockaddr_in6* in6 = (const struct sockaddr_in6*)sa;
        return ipv6_to_string(in6, with_port);
    }

    errno = EAFNOSUPPORT;
    return std::string();
}

Fd::Fd() : _fd(-1) {}
Fd::Fd(int fd) : _fd(fd) {}

Fd::~Fd() {
    if (_fd >= 0) {
        ::close(_fd);
        _fd = -1;
    }
}

bool Fd::valid() const { return _fd >= 0; }
int  Fd::get() const { return _fd; }

void Fd::reset(int fd) {
    if (_fd >= 0)
        ::close(_fd);
    _fd = fd;
}

int Fd::release() {
    int tmp = _fd;
    _fd = -1;
    return tmp;
}
}
}