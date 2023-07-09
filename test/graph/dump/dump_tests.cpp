// #include <gtest/gtest.h>
// #include <aon/hashing/dump.hpp>
//
// #include <string>
// #include <vector>
//
// static auto compare_files(std::string file1, std::string file2) -> bool {
//     // read a file as binary and compare it to another file
//     std::ifstream f1(file1, std::ios::binary | std::ios::ate);
//     std::ifstream f2(file2, std::ios::binary | std::ios::ate);
//
//     if (f1.fail() || f2.fail()) {
//         return false; // file problem
//     }
//
//     if (f1.tellg() != f2.tellg()) {
//         return false; // size mismatch
//     }
//
//     // seek back to beginning and use std::equal to compare contents
//     f1.seekg(0, std::ios::beg);
//     f2.seekg(0, std::ios::beg);
//
//     return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
//                       std::istreambuf_iterator<char>(),
//                       std::istreambuf_iterator<char>(f2.rdbuf()));
// }
//
// class graph_dump_tests : public ::testing::Test {
// protected:
//     void SetUp() override {
//         // data from the file
//         data = std::vector<int> {{
//                 334,  3771, 4984, 1709, 4252, 4410, 1895, 1909, 3399, 76,   70,   3233,
//                 2265, 3895, 3493, 1077, 3457, 1276, 954,  3712, 4537, 1017, 123,  1784,
//                 230,  2566, 3795, 1583, 2341, 2824, 714,  3125, 1652, 1995, 1674, 214,
//                 4247, 3579, 2479, 1828, 285,  2284, 910,  2984, 2122, 4064, 258,  1821,
//                 3293, 3049, 307,  454,  612,  1264, 4064, 4626, 983,  277,  1726, 1940,
//                 811,  856,  1081, 3184, 2201, 128,  3154, 2034, 1854, 2946, 1314, 4377,
//                 1595, 980,  1311, 1981, 3847, 2122, 636,  3813, 3748, 1048, 2366, 2780,
//                 4359, 4153, 4092, 996,  4788, 232,  2206, 2523, 4538, 4326, 1513, 1150,
//                 2483, 2619, 3649, 3763,
//             }
//         };
//
//         // dump the data to a file
//         aon::hashing::dump<int>(data, assets_dir + filename);
//     }
//
//     void TearDown() override {
//         // remove the file
//         std::remove((assets_dir + filename).c_str());
//     }
//
//     std::string filename = "dump_test.aon";
//     std::vector<int> data;
//     std::string assets_dir = "./test/hashing/load/assets/";
//     std::string assets_file = "file_100_unix.aon";
// };
//
// TEST_F(hashing_dump_tests, hashing_dump_file_100_unix) {
//     auto res = compare_files(assets_dir + filename, assets_dir + assets_file);
//     ASSERT_TRUE(res);
// }
