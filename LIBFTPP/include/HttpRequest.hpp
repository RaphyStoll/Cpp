#pragma once

#include <string>
#include <map>
#include <cstddef> // size_t

namespace libftpp {

class HttpRequest {
private:
	//canonique en priver pour empecher l'instnciation
	//C++11 tu peut HttpRequest() = delete;
	// mais en 98 pour eviter HttpRequest a();
	// pas d'autre moyen que de mettr en priver
	HttpRequest(const HttpRequest& other);
	HttpRequest& operator=(const HttpRequest& other);

	// --- Données ---
	std::string _method;	// "GET", "POST", ...
	std::string _target;	// "/path?x=1"
	std::string _version;	// "HTTP/1.1"
	std::map<std::string, std::string> _headers; // clés normalisées en lowercase

	// Normalise une clé de header: trim + lowercase ASCII
	static std::string normalizeHeaderKey(const std::string& key);
	static std::string normKey(const std::string& k);
public:
	HttpRequest();
	~HttpRequest();

	// Reset complet (réutilisable en keep-alive)
	void clear();

	// line: ex "GET /path HTTP/1.1"
	bool parseRequestLine(const std::string& line);

	// line: ex "Host: example.com"
	// Retourne false si format invalide.
	// Politique sur doublons: à définir (voir notes).
	bool parseHeaderLine(const std::string& line);

	const std::string& getMethod() const;
	const std::string& getTarget() const;
	const std::string& getVersion() const;

	// --- Headers (case-insensitive via normalisation) ---
	bool hasHeader(const std::string& key) const;

	// Si absent, retourne def.
	std::string getHeader(const std::string& key, const std::string& def = "") const;

	// Content-Length (strict digits) -> true si présent et valide
	bool contentLength(size_t& out) const;


};
}
