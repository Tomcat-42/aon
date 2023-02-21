#pragma once

#include <cstdint>
#include <vector>
#include <tuple>
#include <string>
namespace aon::knapsack {

/// Dumps a knapsack problem data to a file.
/// @param filename The name of the file to load.
/// @param capacity The capacity of the knapsack.
/// @param benefits The benefits of the items.
/// @param weights The weights of the items.
///   An  example:
///   300 -> capacity
///   98 99 100 101 102 103 104 105 -> benefits
///   1 2 3 4 5 6 7 8 -> weights
void dump(std::string const &filename, std::intmax_t capacity, const std::vector<std::intmax_t>& benefits, const std::vector<std::intmax_t>& weights);

}
