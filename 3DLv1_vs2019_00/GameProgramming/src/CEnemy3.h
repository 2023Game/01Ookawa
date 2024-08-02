#ifndef CENEMY3_H
#define CENEMY3_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"
#include "CEffect.h"
#include "CCollisionManager.h"
#include "CPlayer.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CEnemy3 : public CCharacter3
{
public:
	//�Փˏ���
	//Collision(�R���C�_1, �R���C�_2)
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	CEnemy3();
	//CEnemy3(�ʒu, ��], �g�k)
	CEnemy3(const CVector& position, const CVector& rotation,
		const CVector& scale);
	//�X�V����
	void Update();
private:
	//���f���f�[�^
	static CModel sModel;
	//�R���C�_
	CCollider mCollider;
};

#endif

