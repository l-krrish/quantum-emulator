#include "qubit.h"
#include <cmath>

StateVector::StateVector(int num_qubits) : n(num_qubits), amplitudes(1 << num_qubits, {0, 0}) {
    amplitudes[0] = {1, 0};
}

int StateVector::num_qubits() const {
    return n;
}

std::complex<double>& StateVector::operator[](size_t i) {
    return amplitudes[i];
}

const std::complex<double>& StateVector::operator[](size_t i) const {
    return amplitudes[i];
}

void StateVector::normalize() {
    double total = 0;
    for (auto& a : amplitudes) total += std::norm(a);
    double mag = std::sqrt(total);
    for (auto& a : amplitudes) a /= mag;
}
