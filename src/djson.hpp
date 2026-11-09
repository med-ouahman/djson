#pragma once

#include <string>
#include "logging.hpp"
#include <vector>
#include <cstdlib>
#include <array>
#include <string_view>
#include "lib/mapped_file.hpp"

enum class djson_exit_code {
	Ok = 0,
	Runtime = 1,
	Usage = 2,
	InvalidArgument = 2,
};

djson_exit_code djson_exit(djson_exit_code);


class djson {
private:
	static constexpr std::array<std::string_view, 2> m_extensions = {
		".json",
		".djson"
	};

private:
	Logging m_logging;
	bool match_extension(const std::string_view& extension);
	std::string extension_of(const std::string_view& filename);
	djson_exit_code parse(const std::string_view& file);
	
public:
	djson();
	~djson();
	djson_exit_code init(const std::vector<std::string>& files);
	Logging& logging_;

};
