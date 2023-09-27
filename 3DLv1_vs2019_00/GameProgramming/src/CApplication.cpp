#include "CApplication.h"
#include "CRectangle.h"
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{

}

void CApplication::Update()
{
	CVector v0, v1, v2, n;
	n.Set(0.0f, 1.0f, 0.0f);
	v0.Set(0.0f, 0.0f, 0.5f);
	v1.Set(1.0f, 0.0f, 0.0f);
	v2.Set(0.0f, 0.0f, -0.5f);

	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	glNormal3f(n.X(), n.Y(), n.Z());
	glVertex3f(v0.X(), v0.Y(), v0.Z());
	glVertex3f(v1.X(), v1.Y(), v1.Z());
	glVertex3f(v2.X(), v2.Y(), v2.Z());


	n.Set(0.0f, 0.0f, 1.0f);
	v0.Set(0.5f, 0.0f, 0.0f);
	v1.Set(0.0f, 1.0f, 0.0f);
	v2.Set(-0.5f, 0.0f, 0.0f);

	glNormal3f(n.X(), n.Y(), n.Z());
	glVertex3f(v0.X(), v0.Y(), v0.Z());
	glVertex3f(v1.X(), v1.Y(), v1.Z());
	glVertex3f(v2.X(), v2.Y(), v2.Z());


	n.Set(1.0f, 0.0f, 0.0f);
	v0.Set(0.0f, 0.5f, 0.0f);
	v1.Set(0.0f, 0.0f, 1.0f);
	v2.Set(0.0f, -0.5f, 0.0f);

	glNormal3f(n.X(), n.Y(), n.Z());
	glVertex3f(v0.X(), v0.Y(), v0.Z());
	glVertex3f(v1.X(), v1.Y(), v1.Z());
	glVertex3f(v2.X(), v2.Y(), v2.Z());

	glEnd();

	CTriangle t0;
	t0.Vertex(CVector(1.0f, 0.0f, 0.5f), CVector(2.0f, 0.0f, 0.0f), CVector(1.0f, 0.0f, -0.5f));
	t0.Normal(CVector(0.0f, 1.0f, 0.0f));
	t0.Render();

	CTriangle t1;
	t1.Vertex(CVector(0.0f, 2.0f, 0.0f), CVector(-0.5f, 1.0f, 0.0f), CVector(0.5f, 1.0f, 0.0f));
	t1.Normal(CVector(0.0f, 0.0f, 1.0f));
	t1.Render();

	CTriangle t2;
	t2.Vertex(CVector(0.0f, 0.5f, 1.0f), CVector(0.0f, 0.0f, 2.0f), CVector(0.0f, -0.5f, 1.0f));
	t2.Normal(CVector(1.0f, 0.0f, 0.0f));
	t2.Render();
}
