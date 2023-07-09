#include <aon/graph/load.hpp>
#include <cstddef>
#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <vector>

class graph_load_tests : public ::testing::Test {
protected:
  void SetUp() override {
    filename_unix = assets_dir + "file_10_unix.aon";
    filename_dos = assets_dir + "file_10_dos.aon";

    size = 10;
    data = {{0, {{3, 9}, {4, 6}, {5, 9}, {9, 8}}},
            {1, {{2, 1}, {4, 4}, {5, 5}, {6, 6}}},
            {2, {{1, 1}, {4, 4}, {6, 5}, {7, 1}, {8, 2}}},
            {3, {{0, 9}, {4, 1}, {5, 7}, {6, 5}, {8, 4}, {9, 5}}},
            {4, {{0, 6}, {1, 4}, {2, 4}, {3, 1}, {5, 5}, {7, 8}, {8, 7}}},
            {5, {{0, 9}, {1, 5}, {3, 7}, {4, 5}, {6, 9}, {8, 3}, {9, 1}}},
            {6, {{1, 6}, {2, 5}, {3, 5}, {5, 9}, {7, 5}, {8, 5}, {9, 3}}},
            {7, {{2, 1}, {4, 8}, {6, 5}, {9, 9}}},
            {8, {{2, 2}, {3, 4}, {4, 7}, {5, 3}, {6, 5}, {9, 1}}},
            {9, {{0, 8}, {3, 5}, {5, 1}, {6, 3}, {7, 9}, {8, 1}}}};
  }

  std::string filename_unix;
  std::string filename_dos;
  std::size_t size;
  std::map<size_t, std::set<std::pair<size_t, size_t>>> data;
  std::string assets_dir = "./test/graph/load/assets/";
};

TEST_F(graph_load_tests, graph_load_file_10_unix) {
  auto [loaded_size, loaded_data] =
    aon::graph::load<std::size_t>(filename_unix);

  ASSERT_EQ(size, loaded_size);
  ASSERT_EQ(data, loaded_data);
}

TEST_F(graph_load_tests, graph_load_file_10_dos) {
  auto [loaded_size, loaded_data] = aon::graph::load<std::size_t>(filename_dos);

  ASSERT_EQ(size, loaded_size);
  ASSERT_EQ(data, loaded_data);
  ASSERT_EQ(data, loaded_data);
}
