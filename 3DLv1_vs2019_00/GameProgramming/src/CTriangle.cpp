#include "CTriangle.h"
#include <stdio.h>
#include "glut.h"

void CTriangle::Vertex(const CVector& v0, const CVector& v1, const CVector& v2) {
	mV[0] = v0;
	mV[1] = v1;
	mV[2] = v2;
}
void CTriangle::Normal(const CVector& n) 
{
	mN[0] = mN[1] = mN[2] = n;
}
void CTriangle::Render()
{
	glBegin(GL_TRIANGLES);
	glNormal3f(mN[0].X(), mN[0].Y(), mN[0].Z());
	glTexCoord2f(mUv[0].X(), mUv[0].Y());
	glVertex3f(mV[0].X(), mV[0].Y(), mV[0].Z());
	glNormal3f(mN[1].X(), mN[1].Y(), mN[1].Z());
	glTexCoord2f(mUv[1].X(), mUv[1].Y());
	glVertex3f(mV[1].X(), mV[1].Y(), mV[1].Z());
	glNormal3f(mN[2].X(), mN[2].Y(), mN[2].Z());
	glTexCoord2f(mUv[2].X(), mUv[2].Y());
	glVertex3f(mV[2].X(), mV[2].Y(), mV[2].Z());
	glEnd();
}

void CTriangle::Normal(const CVector& v0, const CVector& v1, const CVector& v2)
{
	mN[0] = v0;
	mN[1] = v1;
	mN[2] = v2;
}

//int MaterialIdx();

int CTriangle::MaterialIdx()
{
	//CTriangleクラスのmMaterialIdxの値を返します。
	return mMaterialIdx;
}

void CTriangle::MaterialIdx(int idx)
{
	//CTriangleクラスのmMaterialIdxに、引数idxの値を代入します。
	mMaterialIdx = idx;
}

void CTriangle::UV(const CVector& v0, const CVector& v1, const CVector& v2)
{
	mUv[0] = v0;
	mUv[1] = v1;
	mUv[2] = v2;
}

