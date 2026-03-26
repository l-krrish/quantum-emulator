#pragma once
#include "qubit.h"
#include <vector>

int measure(StateVector& sv, int qubit);
std::vector<int> measure_all(StateVector& sv);