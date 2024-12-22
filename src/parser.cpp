
#include "parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <nlohmann/json.hpp> // Properly include the header

using json = nlohmann::json;

// TXT file parser
class TxtParser : public Parser {
public:
    std::vector<Point> parse(const std::string& file_path) override {
        std::vector<Point> points;
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open TXT file: " + file_path);
        }
        std::string line;
        while (std::getline(file, line)) {
            size_t colon = line.find(':');
            size_t comma = line.find(',');
            if (colon == std::string::npos || comma == std::string::npos) {
                throw std::runtime_error("Invalid format in TXT file: " + line);
            }
            Point point;
            point.group = line.substr(0, colon);
            point.x = std::stoi(line.substr(colon + 1, comma - colon - 1));
            point.y = std::stoi(line.substr(comma + 1));
            points.push_back(point);
        }
        return points;
    }
};

// BIN file parser
class BinParser : public Parser {
public:
    std::vector<Point> parse(const std::string& file_path) override {
        std::vector<Point> points;
        std::ifstream file(file_path, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open BIN file: " + file_path);
        }
        struct PointBinary {
            uint32_t group : 8;
            uint32_t x : 12;
            uint32_t y : 12;
        };
        PointBinary pb;
        while (file.read(reinterpret_cast<char*>(&pb), sizeof(pb))) {
            Point point;
            point.group = std::to_string(pb.group);
            point.x = pb.x;
            point.y = pb.y;
            points.push_back(point);
        }
        return points;
    }
};

// JSON file parser
class JsonParser : public Parser {
public:
    std::vector<Point> parse(const std::string& file_path) override {
        std::vector<Point> points;
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open JSON file: " + file_path);
        }
        json j;
        file >> j;
        for (const auto& item : j["points"]) {
            Point point;
            point.group = item["group"];
            point.x = item["x"];
            point.y = item["y"];
            points.push_back(point);
        }
        return points;
    }
};

// Factory function implementation
Parser* createParser(const std::string& file_extension) {
    if (file_extension == "txt") return new TxtParser();
    if (file_extension == "bin") return new BinParser();
    if (file_extension == "json") return new JsonParser();
    throw std::invalid_argument("Unsupported file extension: " + file_extension);
}
