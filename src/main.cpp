#include <aon/graph/load.hpp>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>
#include <vector>

int main(int argc, char* argv[]) {
  std::cout << argc << std::endl;
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <datafile> <dumpfile>" << std::endl;
    return 1;
  }

  std::cout << "datafile: " << argv[1] << std::endl;
  const auto& [size, data] = aon::graph::load<std::size_t>(argv[1]);
  std::cout << "size: " << size << std::endl;

  // print data
  for (const auto& [node, edges] : data) {
    std::cout << node << ": ";
    for (const auto& [edge, weight] : edges) {
      std::cout << "(" << edge << ", " << weight << ") ";
    }
    std::cout << std::endl;
  }

  return 0;
}
