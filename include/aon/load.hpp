#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include <vector>

namespace aon {
/**
 * @brief Load a file containing multiple values of type T into a vector.
 * @param filename The file to load
 * @return A vector containing the values from the file
 */
template <typename T> std::vector<T> load(std::string filename) {
  std::vector<T> data;
  T token;

  try {
    std::ifstream file(filename, std::ios::binary);

    // open
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file");
    }

    // read
    while (file >> token) {
      data.push_back(token);
    }
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return data;
}
} // namespace aon
