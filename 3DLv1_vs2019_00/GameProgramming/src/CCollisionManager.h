#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H

//�Փˏ����͈͂�藣��Ă���R���C�_�͏Փˏ������Ȃ�
#define COLLISIONRANGE 30

#include "CTaskManager.h"
#include "CCollider.h"


class CCollisionManager : public CTaskManager
{
public:
	//�Փˏ���
	void Collision();

	void Collision(CCollider* c, int range);

	//�C���X�^���X�̎擾
	static CCollisionManager* Instance();
private:
	//�}�l�[�W���̃C���X�^���X
	static CCollisionManager* mpInstance;
};

#endif
