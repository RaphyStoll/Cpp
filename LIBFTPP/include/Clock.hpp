#pragma once

#include <stdint.h>
#include <string>

namespace libftpp {
namespace time {

typedef uint64_t timestamp_us_t;
typedef uint64_t timestamp_ms_t;

class Clock {
private:
	Clock();
	Clock(const Clock&);
	Clock& operator=(const Clock&);
	~Clock();

public:
	static timestamp_us_t now_us();
	static timestamp_ms_t now_ms();
	static std::string elapsed_compact_since(timestamp_ms_t start_time_ms);
	static std::string elapsed_compact_since_us(timestamp_us_t start_time_us);
};

class Timeout {
private:
	timestamp_ms_t _last_activity_ms;
	timestamp_ms_t _timeout_ms;

public:
	Timeout();
	Timeout(timestamp_ms_t timeout_ms);

	void set_timeout_ms(timestamp_ms_t timeout_ms);
	timestamp_ms_t timeout_ms() const;

	void touch(timestamp_ms_t now_ms);
	timestamp_ms_t last_activity_ms() const;

	timestamp_ms_t elapsed_since(timestamp_ms_t now_ms) const;
	bool expired(timestamp_ms_t now_ms) const;

	timestamp_ms_t deadline_ms() const;
};

}
}
