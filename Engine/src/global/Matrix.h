#pragma once
#include "Shorts.h"

typedef struct TransMatrix {
	vec3 top = { 1.0f, 0.0f, 0.0f };
	vec3 mid = { 0.0f, 1.0f, 0.0f };
} TransMatrix;

TransMatrix matrixMult(TransMatrix& a, TransMatrix& b);
TransMatrix matrixAdd(TransMatrix& a, TransMatrix& b);