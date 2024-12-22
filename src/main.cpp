
#include <iostream>
#include "parser.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2> ... <fileN>" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string file_path = argv[i];
        std::string extension = getFileExtension(file_path);
        try {
            Parser* parser = createParser(extension);
            std::vector<Point> points = parser->parse(file_path);
            delete parser; // Clean up parser object

            std::cout << "File: " << file_path << std::endl;
            for (const auto& point : points) {
                std::cout << "Group: " << point.group << ", X: " << point.x << ", Y: " << point.y << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error processing file " << file_path << ": " << e.what() << std::endl;
            return 1;
        }
    }

    return 0;
}
