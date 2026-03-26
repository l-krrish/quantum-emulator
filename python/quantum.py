import sys
import numpy as np

sys.path.insert(0, 'build')
import qemu_ext


class QuantumCircuit:
    def __init__(self, num_qubits):
        self.num_qubits = num_qubits
        self.circuit = qemu_ext.Circuit(num_qubits)

    def h(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.H(), qubit)
        return self

    def x(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.X(), qubit)
        return self

    def y(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.Y(), qubit)
        return self

    def z(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.Z(), qubit)
        return self

    def s(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.S(), qubit)
        return self

    def t(self, qubit):
        self.circuit.add_gate(qemu_ext.Gate.T(), qubit)
        return self

    def cnot(self, control, target):
        self.circuit.add_gate(qemu_ext.Gate.CNOT(), control, target)
        return self

    def run(self):
        sv = self.circuit.run()
        return np.array([sv[i] for i in range(2 ** self.num_qubits)])

    def measure(self, qubit):
        sv = self.circuit.run()
        return qemu_ext.measure(sv, qubit)

    def measure_all(self):
        sv = self.circuit.run()
        return qemu_ext.measure_all(sv)

    def to_json(self):
        return self.circuit.to_json()


if __name__ == "__main__":
    qc = QuantumCircuit(2)
    qc.h(0).cnot(0, 1)
    print("State:", qc.run())
    print("Measure:", qc.measure_all())
