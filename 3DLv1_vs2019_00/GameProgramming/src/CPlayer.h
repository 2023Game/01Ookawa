#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"
#include "CCollisionManager.h"

/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CCharacter3
{
public:
	//インスタンスのポインタの取得
	static CPlayer* Instance();
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	CPlayer();
	//CPlayer(位置, 回転, スケール)
	CPlayer(const CVector& pos, const CVector& rot
		, const CVector& scale);
	//更新処理
	void Update();
	//衝突処理
	void Collision();
private:
	//プレイヤーのインスタンス
	static CPlayer* spInstance;
	CColliderLine mLine; //線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	CInput mInput;
};

#endif
