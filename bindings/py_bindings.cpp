#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include "circuit.h"
#include "simulator.h"

namespace py = pybind11;

PYBIND11_MODULE(qemu_ext, m) {

    py::class_<Gate>(m, "Gate")
        .def(py::init<std::string, const Matrix&>())
        .def("mat", &Gate::mat)
        .def("name", &Gate::name)
        .def_static("H", &Gate::H)
        .def_static("X", &Gate::X)
        .def_static("Y", &Gate::Y)
        .def_static("Z", &Gate::Z)
        .def_static("S", &Gate::S)
        .def_static("T", &Gate::T)
        .def_static("CNOT", &Gate::CNOT);

    py::class_<Circuit>(m, "Circuit")
        .def(py::init<int>())
        .def("add_gate", py::overload_cast<Gate, int>(&Circuit::add_gate))
        .def("add_gate", py::overload_cast<Gate, int, int>(&Circuit::add_gate))
        .def("run", &Circuit::run)
        .def("to_json", &Circuit::to_json);

    py::class_<StateVector>(m, "StateVector")
        .def(py::init<int>())
        .def("num_qubits", &StateVector::num_qubits)
        .def("normalize", &StateVector::normalize)
        .def("__getitem__", [](const StateVector& sv, size_t i) {
            return sv[i];
        });

    m.def("measure", &measure);
    m.def("measure_all", &measure_all);
}
