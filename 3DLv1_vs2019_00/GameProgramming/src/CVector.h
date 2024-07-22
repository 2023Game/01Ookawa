#include "CMatrix.h"

#ifndef CVECTOR_H
#define CVECTOR_H

class CVector
{
public:
	//正規化
	//大きさ1のベクトルを返す
	CVector Normalize() const;
	//外積
	//Cross(ベクトル)
	CVector Cross(const CVector& v) const;
	//*演算子のオーバーロード
	//CVector * float の演算結果を返す
	CVector operator*(const float& f) const;
	//内積
	//Dot(ベクトル)
	float Dot(const CVector& v) const;
	//ベクトルの長さを返す
	float Length() const;
	CVector operator*(const CMatrix& m);
	CVector operator-(const CVector& v) const;
	CVector operator+(const CVector& v) const;
	CVector();
	CVector(float x, float y, float z);
	void Set(float x, float y, float z);
	float X() const;
	float Y() const;
	float Z() const;
private:
	float mX, mY, mZ;
};
#endif