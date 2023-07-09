#pragma once

#include <cstddef>
#include <fstream>
#include <unordered_map>
#include <vector>
namespace aon::graph {
/**
 * @brief dump graph to file
 *
 * @tparam T
 * @param filename
 * @param graph
 */
template <typename T>
auto dump(std::string const& filename, std::size_t size, std::unordered_map<T, std::vector<T>> const& graph) -> void {
    std::ofstream ofs(filename);
    ofs << size << std::endl;
    for (auto const& [key, value] : graph) {
        ofs << key << " ";
        for (auto const& v : value) {
            ofs << v << " ";
        }
        ofs << std::endl;
    }
}
} // namespace aon::grap
