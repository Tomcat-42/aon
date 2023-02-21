#include <pybind11/pybind11.h>

namespace py = pybind11;

void sorting(py::module_ &m);
void knapsack(py::module_ &m);

PYBIND11_MODULE(pyaon, m) {
    m.doc() = "Interact with the AON (Andrezao Object Notation) file format";

    sorting(m);
    knapsack(m);
}
