#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"
#include "CCollisionManager.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter3
{
public:
	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	CPlayer();
	//CPlayer(�ʒu, ��], �X�P�[��)
	CPlayer(const CVector& pos, const CVector& rot
		, const CVector& scale);
	//�X�V����
	void Update();
	//�Փˏ���
	void Collision();
private:
	//�v���C���[�̃C���X�^���X
	static CPlayer* spInstance;
	CColliderLine mLine; //�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;
	CInput mInput;
};

#endif
