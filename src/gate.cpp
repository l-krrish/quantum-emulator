#include "gate.h"
#include <cmath>

using cd = std::complex<double>;
static const double s = std::sqrt(2.0);

Gate::Gate(const std::string& name, const Matrix& matrix) : _name(name), _matrix(matrix) {}

const Matrix& Gate::mat() const { return _matrix; }
const std::string& Gate::name() const { return _name; }

Gate Gate::H() {
    return Gate("H", {{cd(1/s,0), cd(1/s,0)}, {cd(1/s,0), cd(-1/s,0)}});
}

Gate Gate::X() {
    return Gate("X", {{cd(0,0), cd(1,0)}, {cd(1,0), cd(0,0)}});
}

Gate Gate::Y() {
    return Gate("Y", {{cd(0,0), cd(0,-1)}, {cd(0,1), cd(0,0)}});
}

Gate Gate::Z() {
    return Gate("Z", {{cd(1,0), cd(0,0)}, {cd(0,0), cd(-1,0)}});
}

Gate Gate::S() {
    return Gate("S", {{cd(1,0), cd(0,0)}, {cd(0,0), cd(0,1)}});
}

Gate Gate::T() {
    return Gate("T", {{cd(1,0), cd(0,0)}, {cd(0,0), std::exp(cd(0, M_PI/4))}});
}

Gate Gate::CNOT() {
    return Gate("CNOT", {
        {cd(1,0), cd(0,0), cd(0,0), cd(0,0)},
        {cd(0,0), cd(1,0), cd(0,0), cd(0,0)},
        {cd(0,0), cd(0,0), cd(0,0), cd(1,0)},
        {cd(0,0), cd(0,0), cd(1,0), cd(0,0)}
    });
}
