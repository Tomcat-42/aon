file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS
  include/**/*.hpp
  src/pyaon/*.cpp
  src/pyaon/**/*.cpp
  src/aon/*.cpp
  src/aon/**/*.cpp
)

pybind11_add_module(pyaon
  ${SOURCE}
  src/pyaon/pyaon.cpp
)

target_include_directories(pyaon PRIVATE include /usr/include /usr/local/include)
