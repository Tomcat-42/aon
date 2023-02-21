#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>
#include <aon/knapsack/dump.hpp>
#include <aon/knapsack/load.hpp>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>


int main(int argc, char *argv[]) {
    std::cout << argc << std::endl;
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <datafile> <dumpfile>" << std::endl;
        return 1;
    }
    const auto &[capacity,weights, values] = aon::knapsack::load(argv[1]);
    std::cout << "capacity: " << capacity << std::endl;
    std::cout << std::endl;
    std::copy(weights.begin(), weights.end(), std::ostream_iterator<intmax_t>(std::cout, " "));
    std::cout << std::endl;
    std::copy(values.begin(), values.end(), std::ostream_iterator<intmax_t>(std::cout, " "));
    std::cout << std::endl;

    aon::knapsack::dump(argv[2],capacity, weights, values);
    return 0;
}
