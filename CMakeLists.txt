file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS
  include/**/*.hpp
  src/aon/*.cpp
  src/libaon/*.cpp
)

pybind11_add_module(daa
  ${SOURCE}
  src/aon/aon.cpp
)

target_include_directories(daa PRIVATE include /usr/include /usr/local/include)
