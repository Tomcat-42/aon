#include <aon/graph/dump.hpp>
#include <cstddef>
#include <gtest/gtest.h>

#include <map>
#include <set>
#include <string>
#include <vector>

static auto compare_files(std::string file1, std::string file2) -> bool {
  // read a file as binary and compare it to another file
  std::ifstream f1(file1, std::ios::binary | std::ios::ate);
  std::ifstream f2(file2, std::ios::binary | std::ios::ate);

  if (f1.fail() || f2.fail()) {
    return false; // file problem
  }

  if (f1.tellg() != f2.tellg()) {
    return false; // size mismatch
  }

  // seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ios::beg);
  f2.seekg(0, std::ios::beg);

  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

class graph_dump_tests : public ::testing::Test {
protected:
  void SetUp() override {
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

    // dump the data to a file
    aon::graph::dump<std::size_t>(assets_dir + filename, {size, data});
  }

  void TearDown() override {
    // remove the file
    std::remove((assets_dir + filename).c_str());
  }

  std::string filename = "dump_test.aon";
  std::size_t size;
  std::unordered_map<std::size_t, std::set<std::pair<std::size_t, std::size_t>>> data;
  std::string assets_dir = "./test/graph/dump/assets/";
  std::string assets_file = "file_10.aon";
};

TEST_F(graph_dump_tests, graph_dump_file_10_unix) {
  auto res = compare_files(assets_dir + filename, assets_dir + assets_file);
  ASSERT_TRUE(res);
}
