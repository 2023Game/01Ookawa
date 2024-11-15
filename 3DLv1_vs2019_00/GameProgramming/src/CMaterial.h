#ifndef CMATERIAL_H
#define CMATERIAL_H
#define MATERIAL_NAME_LEN 64 

#include "CTexture.h"

class CMaterial 
{
public:
	//頂点数の設定
	//VertexNum(頂点数)
	void VertexNum(int num);
	//頂点数の取得
	int VertexNum();
	CTexture* Texture();
	void Disabled();
	CMaterial();
	void Enabled();
	char* Name();
	void Name(char* name);
	float* Diffuse();
private:
	int mVertexNum;
	CTexture mTexture;
	char mName[MATERIAL_NAME_LEN + 1];
	float mDiffuse[4];
};

#endif
