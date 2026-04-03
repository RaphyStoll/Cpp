#include "libftpp.hpp"

class Pmerge {
	private:
		libftpp::debug::DebugLogger _debug;
		libftpp::debug::DebugLogger _info;
		libftpp::debug::DebugLogger _warning;
		libftpp::debug::DebugLogger _error;
	public:
	Pmerge() : _debug("DEBUG"),_info("INFO"),_warning("WARNING"),_error("ERRROR") {}; 
	~Pmerge() {};
};