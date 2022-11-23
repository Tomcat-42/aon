#include <aon/dump.hpp>
#include <aon/load.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <string>
#include <vector>

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<int>);
PYBIND11_MAKE_OPAQUE(std::vector<float>);
PYBIND11_MAKE_OPAQUE(std::vector<std::string>)

PYBIND11_MODULE(pyaon, m) {
  m.doc() = "Interact with the aon (Andrezao Object Notation) file format";

  m.def("load", &aon::load<int>, "Load an aon file into a vector of integers");
  m.def("dump", &aon::dump<int>, "Dump a vector of integers into an aon file");

  // binding std::vector<int> to python
  py::bind_vector<std::vector<int>>(m, "vector_int");
  py::bind_vector<std::vector<float>>(m, "vector_float");
  py::bind_vector<std::vector<std::string>>(m, "vector_string");

  py::implicitly_convertible<py::list, std::vector<int>>();
  py::implicitly_convertible<py::list, std::vector<float>>();
  py::implicitly_convertible<py::list, std::vector<std::string>>();
}
