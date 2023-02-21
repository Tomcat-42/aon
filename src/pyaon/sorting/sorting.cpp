#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <aon/sorting/load.hpp>
#include <aon/sorting/dump.hpp>
#include <vector>

namespace py = pybind11;

void sorting(py::module_ &m) {
    auto m_sorting = m.def_submodule("sorting", "Parse and dump AON files (sorting variant)");
    m_sorting.def("load", &aon::sorting::load<int>, "Load an AON file (sorting variant)");
    m_sorting.def("dump", &aon::sorting::dump<int>, "Dump an AON file (sorting variant)");
}
