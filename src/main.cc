
#include <vector>
#include "djson.hpp"
#include "djson_usage.hpp"
#include <iostream>


int main(int argc, const char *argv[]) {

	if (argc < 2) {
		djson_exit(djson_usage(djson_usage_code::Argument));
	}

	std::vector<std::string> files(argc - 1);

	for (int i = 0; i < argc - 1; ++i) {
		files[i] = argv[i + 1];
	}

	djson context;
	auto code = context.init(files);
	return static_cast<int>(code);
}

