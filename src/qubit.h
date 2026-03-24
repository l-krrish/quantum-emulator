#pragma once
#include <vector>
#include <complex>

class StateVector{
    private:
        int n;
        std::vector<std::complex<double>> amplitudes;
    public:
        explicit StateVector(int num_qubits);
        int num_qubits() const;
        std::complex<double>& operator[](size_t i);
        const std::complex<double>& operator[](size_t i) const;
        void normalize();
};
