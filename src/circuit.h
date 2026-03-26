#pragma once
#include "qubit.h"
#include "gate.h"
#include <vector>
#include <optional>
#include <string>

struct GateOp{
    Gate gate;
    int target;
    std::optional<int> control;
};

class Circuit {
    private:
        int n;
        std::vector<GateOp> ops;
    public:
        Circuit(int num_qubits);
        void add_gate(Gate g, int target);
        void add_gate(Gate g, int control, int target);
        StateVector run() const; 
        std::string to_json() const;
        static Circuit from_json(const std::string& json);
};