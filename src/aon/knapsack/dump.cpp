#include <cstdint>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
namespace aon::knapsack {

/// Dumps a knapsack problem data to a file.
/// @param filename The name of the file to load.
/// @param capacity The capacity of the knapsack.
/// @param indexes The indexes of the items.
/// @param benefits The benefits of the items.
/// @param weights The weights of the items.
///   An  example:
///   300 -> capacity
///   1 2 3 4 5 6 7 8 -> indexes
///   98 99 100 101 102 103 104 105 -> benefits
///   1 2 3 4 5 6 7 8 -> weights
void dump(std::string const &filename, std::intmax_t capacity, const std::vector<std::intmax_t>& benefits, const std::vector<std::intmax_t>& weights) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    file << capacity << std::endl;


    // write all vector elements separated by a space into a single line, and write it to the file
    auto write_line = [&file](const std::vector<std::intmax_t>& vec) {
        for (auto it = vec.begin(); it != vec.end(); ++it)
            file << *it << ((it != vec.end() - 1) ? " " : "\n");
    };

    write_line(benefits);
    write_line(weights);
}

}
