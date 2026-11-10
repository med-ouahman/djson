
#include "djson.hpp"

djson::djson()
	: m_logging(),
	logging_(m_logging) {
}

djson::~djson() {

}

djson_exit_code djson_exit(djson_exit_code code) {
	int c = static_cast<int>(code);
	std::exit(c);
	return code;
}

djson_exit_code djson::init(const std::vector<std::string>& files) {

	for (const auto& file: files) {
		auto extension = djson::extension_of(file);
		if (!djson::match_extension(extension)) {
			this->logging_.error("Error: `%s' not a supported extension\n", file.c_str());
			return djson_exit_code::InvalidArgument;
		}
		this->parse(file);
	}

	return djson_exit_code::Ok;
}

bool djson::match_extension(const std::string_view& extension) {

	for (auto const& ext: m_extensions) {
		if (extension == ext) return true;
	}

	return false;
}

std::string djson::extension_of(const std::string_view& s) {
	
	auto dot = s.find_last_of(".");
	if (dot == 0 || dot == std::string::npos) {
		return "";
	}
	
	return std::string(s).substr(dot);
}

djson_exit_code djson::parse(const std::string_view& file) {

	MappedFile mapped{file};

	if (mapped.failed()) {
		this->logging_.error("Error: %s\n", mapped.failure_reason());
		return djson_exit_code::Runtime;
	}
	
	DjsonParser parser(DjsonParser::from_c_str(mapped.data(), mapped.size()));
	return djson_exit_code::Ok;
}
