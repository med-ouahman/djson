
#include <fcntl.h>
#include "mapped_file.hpp"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cerrno>
#include <cstring>

MappedFile::MappedFile(const std::string_view& filename)
    : m_fd(-1),
    m_data(nullptr),
    m_size(0),
    m_reason(NULL),
    m_fail(false)
{

    int fd = open(filename.data(), O_RDONLY);
    if (fd < 0) {
        m_fail = true;
        m_reason = strerror(errno);
        return;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {

        m_fail = true;
        m_reason = strerror(errno);
        return;
    }
    
    char *data = static_cast<char*>(mmap(
        NULL,
        st.st_size,
        PROT_READ,
        MAP_PRIVATE,
        fd,
        0
    ));

    if (data == MAP_FAILED) {
        m_fail = true;
        m_reason = strerror(errno);
        return;
    }

    m_fd = fd;
    m_data = data;
    m_size = st.st_size;

    write(1, m_data, m_size);
}

MappedFile::~MappedFile() {

    if (m_fd >= 0) {
        ::close(m_fd);
        m_fd = 0;
    }

    m_data = nullptr;
}

const char* MappedFile::data() const {
    return m_data;
}

size_t MappedFile::size() const {
    return m_size;
}


bool MappedFile::failed() const {
    return m_fail;
}

const char* MappedFile::failure_reason() const {
    return m_reason;
}