cmake_minimum_required(VERSION 3.15)
project(quantum_emulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

add_library(libqemu STATIC
    src/qubit.cpp
    src/gate.cpp
    src/circuit.cpp
    src/simulator.cpp
)
target_include_directories(libqemu PUBLIC src)
set_target_properties(libqemu PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(qemu_ext bindings/py_bindings.cpp)
target_link_libraries(qemu_ext PRIVATE libqemu)
target_include_directories(qemu_ext PRIVATE src)
