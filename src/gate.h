#pragma once
#include <vector>
#include <complex>
#include <string>

using Matrix = std::vector<std::vector<std::complex<double>>>;

class Gate{
    private:
    std::string _name;
    Matrix _matrix;

    public:
    Gate(const std::string& name, const Matrix& matrix);
    const Matrix& mat() const;
    const std::string& name() const;

    static Gate H();
    static Gate X();
    static Gate Y();
    static Gate Z();
    static Gate S();
    static Gate T();
    static Gate CNOT();
};