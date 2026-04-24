# ⚛️ Quantum Computer Emulator

A quantum circuit simulator with a C++17 core and Python interface via pybind11.

## ✨ Features

- 🧮 State vector simulation for n-qubit systems
- 🔀 Quantum gates: H, X, Y, Z, S, T, CNOT
- 🎲 Probabilistic measurement with state collapse
- 🐍 Python API for building and running circuits
- 📄 JSON circuit serialization

## 📋 Prerequisites

- 🐧 Ubuntu / WSL
- 🔧 g++ with C++17 support
- 🏗️ CMake 3.15+
- 🐍 Python 3.8+
- 📦 pybind11 (`pip install pybind11`)
- 📦 numpy (`pip install numpy`)

## 🚀 Build

```bash
python3 -m venv venv
source venv/bin/activate
pip install pybind11 numpy

mkdir -p build && cd build
cmake .. -Dpybind11_DIR=$(python3 -c "import pybind11; print(pybind11.get_cmake_dir())")
cmake --build .
```

## 💻 Usage

```python
from python.quantum import QuantumCircuit

# 🔔 Create a Bell state
qc = QuantumCircuit(2)
qc.h(0).cnot(0, 1)

# 👀 View state vector
print(qc.run())
# [0.70710678+0.j  0.+0.j  0.+0.j  0.70710678+0.j]

# 📏 Measure all qubits
print(qc.measure_all())
# [0, 0] or [1, 1]
```

## 📁 Project Structure

```
quantum-emulator/
├── 🏗️ CMakeLists.txt              # Build configuration
├── 📂 src/
│   ├── qubit.h / qubit.cpp        # 🧊 State vector representation
│   ├── gate.h / gate.cpp          # 🚪 Quantum gate definitions
│   ├── circuit.h / circuit.cpp    # 🔌 Circuit builder and executor
│   └── simulator.h / simulator.cpp # 🎲 Measurement
├── 📂 bindings/
│   └── py_bindings.cpp            # 🔗 pybind11 Python bindings
└── 📂 python/
    └── quantum.py                 # 🐍 High-level Python API
```

## 🔀 Available Gates

| Gate | Description |
|------|-------------|
| 🅷  | Hadamard — creates superposition |
| 🅧  | Pauli-X — bit flip |
| 🅨  | Pauli-Y |
| 🅩  | Pauli-Z — phase flip |
| 🇸  | Phase gate (π/2) |
| 🇹  | T gate (π/4) |
| 🔗  | CNOT — Controlled-NOT (2-qubit) |

---

