#include <pybind11/pybind11.h>

namespace py = pybind11;

void sorting(py::module_& m);
void knapsack(py::module_& m);
void hashing(py::module_& m);
void graph(py::module_& m);

PYBIND11_MODULE(pyaon, m) {
  m.doc() = "Interact with the AON (Andrezao Object Notation) file format";

  sorting(m);
  knapsack(m);
  hashing(m);
  graph(m);
}
