#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace aon::graph {

template <typename T>
auto load(std::string const& filename)
  -> std::pair<std::size_t,
               std::unordered_map<T, std::set<std::pair<size_t, T>>>> {
  std::size_t size;
  std::unordered_map<T, std::set<std::pair<size_t, T>>> graph;

  try {
    std::ifstream file(filename);

    if (!file) {
      throw std::runtime_error("Could not open file");
    }

    /* First, read the number of elements from the file. */
    file >> size;

    /* Then, we will read `size` lines from the file.
     * In each line, we will read `size` elements of type `T` and store
     * them in a vector.
     * After, we will map the vector to (i, weights) where i is the index of the
     * vector and weights are the non-zero elements of the vector.
     * After, we will filter out the zero elements and store the result in the
     * graph[i].
     * */
    for (std::size_t i = 0; i < size; ++i) {
      std::set<std::pair<size_t, T>> weights;
      for (std::size_t j = 0; j < size; ++j) {
        T weight;
        file >> weight;
        if (weight != 0) {
          weights.insert({j, weight});
        }
      }

      graph[i] = weights;
    }

  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return {size, graph};
}

} // namespace aon::graph
