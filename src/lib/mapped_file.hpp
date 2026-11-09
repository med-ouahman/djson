
#pragma once

#include <cstddef>
#include <string_view>

class MappedFile {
private:
    int m_fd;
    char* m_data;
    size_t m_size;
    char* m_reason;
    bool m_fail;

public:
    MappedFile(const std::string_view& filename);
    ~MappedFile();
    const char* data() const;
    size_t size() const;
    bool failed() const;
    const char* failure_reason() const;
};
