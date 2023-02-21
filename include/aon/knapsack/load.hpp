#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <tuple>
namespace aon::knapsack {

/// Loads a knapsack problem data from a file.
/// @param filename The name of the file to load.
///   An  example:
///   300 -> capacity
///   98 99 100 101 102 103 104 105 -> benefits
///   1 2 3 4 5 6 7 8 -> weights
/// @return A tuple with the capacity, the indexes, the benefits and the weights.
std::tuple<std::intmax_t, std::vector<std::intmax_t>, std::vector<std::intmax_t>> load(std::string const& filename);

}
