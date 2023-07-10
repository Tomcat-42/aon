#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <aon/graph/dump.hpp>
#include <aon/graph/load.hpp>
#include <vector>

namespace py = pybind11;

void graph(py::module_& m) {
  auto m_graph =
    m.def_submodule("graph", "Parse and dump AON files (graph variant)");
  m_graph.def("load", &aon::graph::load<std::size_t>,
              "Load an AON file (graph variant)");
  m_graph.def("dump", &aon::graph::dump<std::size_t>,
              "Dump an AON file (graph variant)");
}
