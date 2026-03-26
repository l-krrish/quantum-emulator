#include "simulator.h"
#include <random>
#include <cmath>

int measure(StateVector& sv, int qubit) {
    int size = 1 << sv.num_qubits();
    double prob0 = 0;
    for (int i = 0; i < size; i++)
        if (!(i & (1 << qubit))) prob0 += std::norm(sv[i]);

    static std::mt19937 rng(std::random_device{}());
    std::discrete_distribution<int> dist({prob0, 1.0 - prob0});
    int outcome = dist(rng);

    for (int i = 0; i < size; i++)
        if (((i >> qubit) & 1) != outcome) sv[i] = 0;
    sv.normalize();
    return outcome;
}

std::vector<int> measure_all(StateVector& sv) {
    std::vector<int> results;
    for (int i = 0; i < sv.num_qubits(); i++)
        results.push_back(measure(sv, i));
    return results;
}
