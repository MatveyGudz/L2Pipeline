
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>

// Structure to store point data
struct Point {
    std::string group;
    unsigned int x;
    unsigned int y;
};

// Abstract class for parsers
class Parser {
public:
    virtual ~Parser() = default;
    virtual std::vector<Point> parse(const std::string& file_path) = 0;
};

// Factory function to create a parser based on file extension
Parser* createParser(const std::string& file_extension);

#endif // PARSER_H
