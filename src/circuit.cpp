#include "circuit.h"
#include <sstream>

Circuit::Circuit(int num_qubits) : n(num_qubits) {}

void Circuit::add_gate(Gate g, int target) {
    ops.push_back({g, target, std::nullopt});
}

void Circuit::add_gate(Gate g, int control, int target) {
    ops.push_back({g, target, control});
}

static void apply_single(StateVector& sv, const Gate& g, int target) {
    int size = 1 << sv.num_qubits();
    for (int i = 0; i < size; i++) {
        if (i & (1 << target)) continue;
        int j = i | (1 << target);
        auto a = sv[i], b = sv[j];
        sv[i] = g.mat()[0][0] * a + g.mat()[0][1] * b;
        sv[j] = g.mat()[1][0] * a + g.mat()[1][1] * b;
    }
}

static void apply_cnot(StateVector& sv, int control, int target) {
    int size = 1 << sv.num_qubits();
    for (int i = 0; i < size; i++) {
        if ((i & (1 << control)) && !(i & (1 << target))) {
            int j = i | (1 << target);
            std::swap(sv[i], sv[j]);
        }
    }
}

StateVector Circuit::run() const {
    StateVector sv(n);
    for (auto& op : ops) {
        if (op.control.has_value())
            apply_cnot(sv, op.control.value(), op.target);
        else
            apply_single(sv, op.gate, op.target);
    }
    return sv;
}

std::string Circuit::to_json() const {
    std::ostringstream ss;
    ss << "{\"num_qubits\":" << n << ",\"ops\":[";
    for (size_t i = 0; i < ops.size(); i++) {
        if (i) ss << ",";
        ss << "{\"gate\":\"" << ops[i].gate.name()
           << "\",\"target\":" << ops[i].target;
        if (ops[i].control.has_value())
            ss << ",\"control\":" << ops[i].control.value();
        ss << "}";
    }
    ss << "]}";
    return ss.str();
}

Circuit Circuit::from_json(const std::string&) {
    return Circuit(1); // stub for now
}
