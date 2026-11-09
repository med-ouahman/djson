
#include <iostream>
#include "djson_usage.hpp"


djson_exit_code djson_usage(djson_usage_code code) {

	switch (code) {
		case djson_usage_code::Argument:
			std::cout << "Usage error: \n";
			return djson_exit_code::Usage;
			break;

	}

	return djson_exit_code::Ok;
}
