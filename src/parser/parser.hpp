
#pragma once

class DjsonParser {
private:
    char* m_input;
    size_t m_size;

public:

    static DjsonParser from_c_str(const char* data, size_t size);
    void parse();
};
