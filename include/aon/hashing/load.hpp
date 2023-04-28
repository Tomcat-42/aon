#pragma once
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

namespace aon::hashing {

template <typename T>
class DataFileLoader {
    static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");

public:
    explicit DataFileLoader(const std::string& filename)
        : file_(filename, std::ios::binary) {
        if (!file_.is_open()) {
            throw std::runtime_error("Could not open file");
        }
    }

    [[nodiscard]] auto load() const -> std::vector<T> {
        return {std::istream_iterator<T>(file_), std::istream_iterator<T>()};
    }

private:
    mutable std::ifstream file_;
};

template <typename T>
[[nodiscard]] auto load(const std::string& filename) -> std::vector<T> {
    try {
        DataFileLoader<T> loader(filename);
        return loader.load();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return {};
}

} // namespace aon::hashing
