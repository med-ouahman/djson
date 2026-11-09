
#pragma once

#include "djson.hpp"

enum class djson_usage_code {
	Argument
};

djson_exit_code djson_usage(djson_usage_code code);

