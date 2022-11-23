#include <aon/dump.hpp>
#include <aon/load.hpp>
#include <stdio.h>
#include <stdlib.h>

void test_dump_load() {
  std::vector<int> data = {1, 2, 3, 4, 5};
  aon::dump(data, "test_dump_load.aon");
  auto loaded_data = aon::load<int>("test_dump_load.aon");
  for (auto &token : loaded_data) {
    printf("%d\n", token);
  }
}

int main() {
  test_dump_load();
  return 0;
}
