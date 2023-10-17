#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"

class CTriangle
{
public:
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	void Normal(const CVector& n);
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
	void Render();
private:
	CVector mV[3];
	CVector mN[3];
};
#endif