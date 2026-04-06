#include "../include/Clock.hpp"

#include <sstream>
#include <sys/time.h>

using namespace libftpp::time;

timestamp_us_t Clock::now_us() {
	struct timeval tv;
	if (gettimeofday(&tv, 0) != 0) {
		return 0;
	}
	timestamp_us_t us =
		(timestamp_us_t)tv.tv_sec * 1000000ULL +
		(timestamp_us_t)tv.tv_usec;
	return us;
}

timestamp_ms_t Clock::now_ms() {
	return now_us() / 1000ULL;
}

std::string Clock::elapsed_compact_since(timestamp_ms_t start_time_ms) {
	return elapsed_compact_since_us(start_time_ms * 1000ULL);
}

std::string Clock::elapsed_compact_since_us(timestamp_us_t start_time_us) {
	timestamp_us_t now_us = Clock::now_us();
	if (now_us == 0)
		return "0ms";

	if (now_us <= start_time_us)
		return "0ms";

	timestamp_us_t remaining = now_us - start_time_us;

	const timestamp_us_t us_per_ms = 1000ULL;
	const timestamp_us_t us_per_s = 1000ULL * us_per_ms;
	const timestamp_us_t us_per_min = 60ULL * us_per_s;
	const timestamp_us_t us_per_h = 60ULL * us_per_min;
	const timestamp_us_t us_per_d = 24ULL * us_per_h;
	const timestamp_us_t us_per_month = 30ULL * us_per_d;
	const timestamp_us_t us_per_year = 365ULL * us_per_d;

	timestamp_us_t years = remaining / us_per_year;
	remaining %= us_per_year;
	timestamp_us_t months = remaining / us_per_month;
	remaining %= us_per_month;
	timestamp_us_t days = remaining / us_per_d;
	remaining %= us_per_d;
	timestamp_us_t hours = remaining / us_per_h;
	remaining %= us_per_h;
	timestamp_us_t minutes = remaining / us_per_min;
	remaining %= us_per_min;
	timestamp_us_t seconds = remaining / us_per_s;
	remaining %= us_per_s;
	timestamp_us_t millis = remaining / us_per_ms;
	remaining %= us_per_ms;
	timestamp_us_t micros = remaining;

	std::ostringstream out;
	bool first = true;

	if (years > 0) {
		out << years << "y";
		first = false;
	}
	if (months > 0) {
		if (!first) out << " ";
		out << months << "mo";
		first = false;
	}
	if (days > 0) {
		if (!first) out << " ";
		out << days << "d";
		first = false;
	}
	if (hours > 0) {
		if (!first) out << " ";
		out << hours << "h";
		first = false;
	}
	if (minutes > 0) {
		if (!first) out << " ";
		out << minutes << "m";
		first = false;
	}
	if (seconds > 0) {
		if (!first) out << " ";
		out << seconds << "s";
		first = false;
	}
	if (millis > 0) {
		if (!first) out << " ";
		out << millis << "ms";
		first = false;
	}
	if (micros > 0) {
		if (!first) out << " ";
		out << micros << "us";
		first = false;
	}

	if (first)
		return "0ms";
	return out.str();
}

Timeout::Timeout(): _last_activity_ms(0), _timeout_ms(0)
{}

Timeout::Timeout(timestamp_ms_t timeout_ms)
	: _last_activity_ms(0), _timeout_ms(timeout_ms)
{}

void Timeout::set_timeout_ms(timestamp_ms_t timeout_ms) {
	_timeout_ms = timeout_ms;
}

timestamp_ms_t Timeout::timeout_ms() const {
	return _timeout_ms;
}

void Timeout::touch(timestamp_ms_t now) {
	_last_activity_ms = now;
}

timestamp_ms_t Timeout::last_activity_ms() const {
	return _last_activity_ms;
}

timestamp_ms_t Timeout::elapsed_since(timestamp_ms_t now) const {
	if (now < _last_activity_ms)
		return 0ULL;
	return now - _last_activity_ms;
}

bool Timeout::expired(timestamp_ms_t now) const {
	if (_timeout_ms == 0)
		return false;
	return elapsed_since(now) >= _timeout_ms;
}

timestamp_ms_t Timeout::deadline_ms() const {
	if (_timeout_ms == 0)
		return 0ULL;
	return _last_activity_ms + _timeout_ms;
}
