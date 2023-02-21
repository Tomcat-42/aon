#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <aon/knapsack/load.hpp>
#include <aon/knapsack/dump.hpp>
#include <vector>

namespace py = pybind11;

void knapsack(py::module_ &m) {
    auto m_knapsack = m.def_submodule("knapsack", "Parse and dump AON files (knapsack variant)");
    m_knapsack.def("load", &aon::knapsack::load, "Load an AON file (knapsack variant)");
    m_knapsack.def("dump", &aon::knapsack::dump, "Dump an AON file (knapsack variant)");
}
