#include <aon/graph/dump.hpp>
#include <aon/graph/load.hpp>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <tuple>
#include <vector>

auto main(int argc, char* argv[]) -> int {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <datafile> <dumpfile>" << std::endl;
    return 1;
  }

  const auto& [size, data] = aon::graph::load<std::size_t>(argv[1]);
  aon::graph::dump<std::size_t>(argv[2], {size, data});

  return EXIT_SUCCESS;
}
