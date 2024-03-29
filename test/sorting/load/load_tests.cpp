#include <gtest/gtest.h>
#include <aon/sorting/load.hpp>

#include <string>
#include <vector>

class load_tests : public ::testing::Test {
protected:
  void SetUp() override {
    filename_unix = assets_dir + "file_100_unix.aon";
    filename_dos = assets_dir + "file_100_dos.aon";

    // data from the file
    data = std::vector<int>{{
        334,  3771, 4984, 1709, 4252, 4410, 1895, 1909, 3399, 76,   70,   3233,
        2265, 3895, 3493, 1077, 3457, 1276, 954,  3712, 4537, 1017, 123,  1784,
        230,  2566, 3795, 1583, 2341, 2824, 714,  3125, 1652, 1995, 1674, 214,
        4247, 3579, 2479, 1828, 285,  2284, 910,  2984, 2122, 4064, 258,  1821,
        3293, 3049, 307,  454,  612,  1264, 4064, 4626, 983,  277,  1726, 1940,
        811,  856,  1081, 3184, 2201, 128,  3154, 2034, 1854, 2946, 1314, 4377,
        1595, 980,  1311, 1981, 3847, 2122, 636,  3813, 3748, 1048, 2366, 2780,
        4359, 4153, 4092, 996,  4788, 232,  2206, 2523, 4538, 4326, 1513, 1150,
        2483, 2619, 3649, 3763,
    }};
  }

  std::string filename_unix;
  std::string filename_dos;
  std::vector<int> data;
  std::string assets_dir = "./test/sorting/load/assets/";
};

TEST_F(load_tests, load_file_100_unix) {
  auto loaded_data = aon::sorting::load<int>(filename_unix);
  ASSERT_EQ(data, loaded_data);
}

TEST_F(load_tests, load_file_100_dos) {
  auto loaded_data = aon::sorting::load<int>(filename_dos);
  ASSERT_EQ(data, loaded_data);
}
