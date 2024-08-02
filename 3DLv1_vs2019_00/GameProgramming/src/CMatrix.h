#ifndef CMATRIX_H
#define CMATRIX_H

class CVector;
class CMatrix
{
public:
	CVector VectorZ() const; //Z���x�N�g���̎擾
	CVector VectorX() const; //X���x�N�g���̎擾
	CVector VectorY() const; //Y���x�N�g���̎擾
	//�t�s��擾
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

