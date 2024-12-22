
#include "utils.h"

std::string getFileExtension(const std::string& file_path) {
    size_t dot_pos = file_path.find_last_of('.');
    if (dot_pos == std::string::npos) return "";
    return file_path.substr(dot_pos + 1);
}
