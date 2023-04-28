#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <aon/hashing/load.hpp>
#include <aon/hashing/dump.hpp>
#include <vector>

namespace py = pybind11;

void hashing(py::module_ &m) {
    auto m_hashing = m.def_submodule("hashing", "Parse and dump AON files (hashing variant)");
    m_hashing.def("load", &aon::hashing::load<int>, "Load an AON file (hashing variant)");
    m_hashing.def("dump", &aon::hashing::dump<int>, "Dump an AON file (hashing variant)");
}
