#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"

class CTriangle
{
public:
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	int MaterialIdx();
	void MaterialIdx(int idx);
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	void Normal(const CVector& n);
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
	void Render();
private:
	CVector mUv[3]; //�e�N�X�`���}�b�s���O
	CVector mV[3];
	CVector mN[3];
	int mMaterialIdx;
};
#endif