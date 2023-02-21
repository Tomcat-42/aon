#include <cstdint>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <iostream>
namespace aon::knapsack {

/// Loads a knapsack problem data from a file.
/// @param filename The name of the file to load.
///   An  example:
///   300 -> capacity
///   98 99 100 101 102 103 104 105 -> benefits
///   1 2 3 4 5 6 7 8 -> weights
/// @return A tuple with the capacity, the indexes, the benefits and the weights.
std::tuple<std::intmax_t, std::vector<std::intmax_t>, std::vector<std::intmax_t>> load(std::string const& filename) {
    // file to read
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    std::intmax_t capacity = 0;
    std::vector<std::intmax_t> benefits;
    std::vector<std::intmax_t> weights;


    // read capacity
    file >> capacity>> std::ws;

    // read one line, and read all the space separated numbers into a vector
    auto read_line = [&file](std::vector<std::intmax_t>& vec) {
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::intmax_t i;
        while (ss >> i) {
            vec.push_back(i);
        }
    };

    // read indexes
    read_line(benefits);
    read_line(weights);

    return std::make_tuple(capacity, benefits, weights);
}

}
