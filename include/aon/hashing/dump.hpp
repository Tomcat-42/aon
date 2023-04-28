#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace aon::hashing {

template <typename T>
class DataFileDumper {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
    explicit DataFileDumper(const std::string& filename)
        : file_(filename, std::ios::binary) {
        if (!file_.is_open()) {
            throw std::runtime_error("Could not open file");
        }
    }

    void dump(const std::vector<T>& data) const {
        std::copy(data.begin(), data.end(), std::ostream_iterator<T>(file_, "\n"));
    }

private:
    mutable std::ofstream file_;
};

template <typename T>
void dump(const std::vector<T>& data, const std::string& filename) {
    try {
        DataFileDumper<T> dumper(filename);
        dumper.dump(data);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

} // namespace aon::hashing
