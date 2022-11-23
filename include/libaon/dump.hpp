#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include <vector>

namespace libaon {
/**
 * @brief Dump a vector of values of type T into a file.
 * @param filename The file to dump to
 * @param data The vector containing the values to dump
 */
template <typename T> void dump(std::vector<T> &data, std::string &filename) {
  try {
    std::ofstream file(filename, std::ios::binary);

    // open
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
    }

    // write
    for (auto &token : data) {
      file << token << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
} // namespace libaon
