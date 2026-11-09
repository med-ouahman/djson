
#pragma once

class Logging {

public:
	void debug(const char* fmt, ...);
	void info(const char* fmt, ...);
	void warn(const char* fmt, ...);
	void error(const char* fmt, ...);
	
};
