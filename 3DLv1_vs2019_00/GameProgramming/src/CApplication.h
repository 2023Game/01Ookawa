#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
#include "CMiss.h"
#include <vector>
#include "CCharacterManager.h"
#include "CModel.h"
#include "CCharacter3.h"
#include "CGame.h"
#include "CSound.h"
#include "CTaskManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CEnemy3.h"


class CApplication
{
private:
	static CUi* spUi;	//UIクラスのポインタ

	//モデルからコライダを生成
	CColliderMesh mColliderMesh;

	//三角コライダの作成
	//CColliderTriangle mColliderTriangle;
	//CColliderTriangle mColliderTriangle2;

	//C5モデル
	CModel mModelC5;
	CModel mBackGround; //背景モデル
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー
	CGame* mpGame;
//	static CTaskManager mTaskManager;

	//モデルビューの逆行列
	static CMatrix mModelViewInverse;
	static CCharacterManager mCharacterManager;
	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};
	EState mState;
//	CCharacter mRectangle;
	CPlayer* mpPlayer;
	static CTexture mTexture;
//	CEnemy* mpEnemy;
//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	CMiss* mpMiss;
	CModel mModel;
//	CCharacter3 mCharacter;
	CPlayer mPlayer;

	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
public:
	~CApplication();
	static CUi* Ui();	//UIクラスのインスタンスを取得
	//モデルビュー行列の取得
	static const CMatrix& ModelViewInverse();
//	static CTaskManager* TaskManager();
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};