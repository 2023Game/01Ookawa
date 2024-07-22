#include "CMatrix.h"

#ifndef CVECTOR_H
#define CVECTOR_H

class CVector
{
public:
	//���K��
	//�傫��1�̃x�N�g����Ԃ�
	CVector Normalize() const;
	//�O��
	//Cross(�x�N�g��)
	CVector Cross(const CVector& v) const;
	//*���Z�q�̃I�[�o�[���[�h
	//CVector * float �̉��Z���ʂ�Ԃ�
	CVector operator*(const float& f) const;
	//����
	//Dot(�x�N�g��)
	float Dot(const CVector& v) const;
	//�x�N�g���̒�����Ԃ�
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