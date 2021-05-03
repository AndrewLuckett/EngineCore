#include "Matrix.h"

TransMatrix matrixMult(TransMatrix & a, TransMatrix & b) {
	TransMatrix out = TransMatrix();
	out.top.x = a.top.x * b.top.x + a.top.y * b.mid.x;
	out.top.y = a.top.x * b.top.y + a.top.y * b.mid.y;
	out.top.z = a.top.x * b.top.z + a.top.y * b.mid.z + a.top.z;

	out.mid.x = a.mid.x * b.top.x + a.mid.y * b.mid.x;
	out.mid.y = a.mid.x * b.top.y + a.mid.y * b.mid.y;
	out.mid.z = a.mid.x * b.top.z + a.mid.y * b.mid.z + a.mid.z;

	return out;
}

TransMatrix matrixAdd(TransMatrix & a, TransMatrix & b){
	TransMatrix out = TransMatrix();
	out.top.x = a.top.x + b.top.x;
	out.top.y = a.top.y + b.top.y;
	out.top.z = a.top.z + b.top.z;

	out.mid.x = a.mid.x + b.mid.x;
	out.mid.y = a.mid.y + b.mid.y;
	out.mid.z = a.mid.z + b.mid.z;

	return out;
}
