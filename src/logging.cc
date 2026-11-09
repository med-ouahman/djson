#include "logging.hpp"
#include <cstdarg>
#include <cstdio>

void Logging::info(const char* fmt, ...) {
	va_list args;
    	va_start(args, fmt);
    	std::vfprintf(stdout, fmt, args);
    	va_end(args);
}

void Logging::error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    std::vfprintf(stderr, fmt, args);
    va_end(args);
}

void Logging::debug(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	std::vfprintf(stdout, fmt, args);
	va_end(args);
}

void Logging::warn(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	std::vfprintf(stdout, fmt, args);
	va_end(args);
}
