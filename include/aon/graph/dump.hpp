#pragma once

#include <cstddef>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace aon::graph {

template <typename T>
auto dump(std::string const& filename,
          std::pair<std::size_t,
                    std::map<T, std::set<std::pair<size_t, T>>>> const& data)
  -> void {
  std::ofstream ofs(filename);
  if (!ofs) {
    throw std::runtime_error("Could not open file");
  }
  auto const& [size, graph] = data;

  // Write the size of the graph.
  ofs << size << '\n';

  // Iterate over all nodes of the graph.
  for (std::size_t i = 0; i < size; ++i) {
    // Create a vector to store the weights of the edges for this node.
    std::vector<T> weights(size, 0);

    // If this node is present in the graph, get its weights.
    if (graph.count(i) > 0) {
      for (auto const& [j, weight] : graph.at(i)) {
        weights[j] = weight;
      }
    }

    // Write the weights to the file.
    for (std::size_t j = 0; j < size; ++j) {
      ofs << weights[j] << (j + 1 < size ? ' ' : '\n');
    }
  }

  ofs.close();
}

} // namespace aon::graph
