#ifndef CMATRIX_H
#define CMATRIX_H

class CVector;
class CMatrix
{
public:
	CVector VectorZ() const; //Z軸ベクトルの取得
	CVector VectorX() const; //X軸ベクトルの取得
	CVector VectorY() const; //Y軸ベクトルの取得
	//逆行列取得
	CMatrix Transpose() const;

	float* M() const;
	const CMatrix operator*(const CMatrix& m) const;
	void M(int row, int col, float value);
	CMatrix Translate(float mx, float my, float mz);
	CMatrix RotateX(float degree);
	CMatrix RotateZ(float degree);
	CMatrix RotateY(float degree);
	void Print();
	CMatrix();
	CMatrix Identity();
	CMatrix Scale(float sx, float sy, float sz);
	float M(int r, int c) const;
private:
	float mM[4][4];
};
#endif

