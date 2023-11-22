#include "CModel.h"
#include <stdio.h>
#include "CVector.h"

int strcmp(const char* s1, const char* s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return s1[i] - s2[i];
}

void CModel::Render()
{
	for (int i = 0; i < mTriangles.size(); i++)
	{
		mpMaterials[mTriangles[i].MaterialIdx()]->Enabled();
		mTriangles[i].Render();
		mpMaterials[mTriangles[i].MaterialIdx()]->Disabled();
	}
}

void CModel::Load(char* obj, char* mtl)
{
	FILE* fp;
	char buf[256];
	std::vector<CVector> vertex;
	std::vector<CVector> normal;
	std::vector<CVector> uv;

	fp = fopen(mtl, "r");
	if (fp == NULL)
	{
		printf("%s file open error￥n", mtl);
		return;
	}
	int idx = 0;

	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		char str[4][64] = { "", "", "", "" };
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		if (strcmp(str[0], "newmtl") == 0)
		{
			CMaterial* pm = new CMaterial();
			pm->Name(str[1]);
			mpMaterials.push_back(pm);
			idx = mpMaterials.size() - 1;
		}
		else if (strcmp(str[0], "Kd") == 0)
		{
			mpMaterials[idx]->Diffuse()[0] = atof(str[1]);
			mpMaterials[idx]->Diffuse()[1] = atof(str[2]);
			mpMaterials[idx]->Diffuse()[2] = atof(str[3]);
		}

		else if (strcmp(str[0], "d") == 0)
		{
			mpMaterials[idx]->Diffuse()[3] = atof(str[1]);
		}

		//先頭がmap_Kdの時、テクスチャを入力する
		else if (strcmp(str[0], "map_Kd") == 0) {
			mpMaterials[idx]->Texture()->Load(str[1]);
		}
	}

	fclose(fp);

	fp = fopen(obj, "r");
	if (fp == NULL)
	{
		printf("%s file open error￥n", obj);
		return;
	}

	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		char str[4][64] = { "", "", "", "" };
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);

		//先頭がvの時、頂点ベクトルを作成して追加する
		if (strcmp(str[0], "v") == 0)
		{
			vertex.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}

		//先頭がfの時、三角形を作成して追加する
		else if (strcmp(str[0], "f") == 0)
		{
			int v[3], n[3];
			//テクスチャマッピングの有無を判定
			if (strstr(str[1], "//")) 
			{
				sscanf(str[1], "%d//%d", &v[0], &n[0]);
				sscanf(str[2], "%d//%d", &v[1], &n[1]);
				sscanf(str[3], "%d//%d", &v[2], &n[2]);
				CTriangle t;
				t.Vertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				t.Normal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				t.MaterialIdx(idx);
				mTriangles.push_back(t);
			}

			else
			{
				//テクスチャマッピング有り
				int u[3]; //テクスチャマッピングの番号
				//頂点と法線の番号取得とマッピングの番号取得
				sscanf(str[1], "%d/%d/%d", &v[0], &u[0], &n[0]);
				sscanf(str[2], "%d/%d/%d", &v[1], &u[1], &n[1]);
				sscanf(str[3], "%d/%d/%d", &v[2], &u[2], &n[2]);
				//三角形作成
				CTriangle t;
				t.Vertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				t.Normal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				//テクスチャマッピングの設定
				t.UV(uv[u[0] - 1], uv[u[1] - 1], uv[u[2] - 1]);
				//マテリアル番号の設定
				t.MaterialIdx(idx);
				//可変長配列mTrianglesに三角形を追加
				mTriangles.push_back(t);
			}
		}

		//先頭がvnの時、法線ベクトルを作成して追加する
		if (strcmp(str[0], "vn") == 0)
		{
			normal.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}

		else if (strcmp(str[0], "usemtl") == 0)
		{
			for (idx = mpMaterials.size() - 1; idx > 0; idx--)
			{
				if (strcmp(mpMaterials[idx]->Name(), str[1]) == 0)
				{
					break;
				}
			}
		}
		else if (strcmp(str[0], "vt") == 0) {
			//可変長配列uvに追加
			//atof(文字列)　文字列からfloat型の値を返す
			uv.push_back(CVector(atof(str[1]), atof(str[2]), 0.0));
		}
	}
	fclose(fp);

}

CModel::~CModel()
{
	printf("通過１\n");
	for (int i = 0; i < mpMaterials.size(); i++)
	{
		printf("通過２\n");
		delete mpMaterials[i];
	}
}

void CModel::Render(const CMatrix& m)
{
	//可変長配列の要素数だけ繰り返し
	for (int i = 0; i < mTriangles.size(); i++)
	{
		//マテリアルの適用
		mpMaterials[mTriangles[i].MaterialIdx()]->Enabled();
		//可変長配列に添え字でアクセスする
		mTriangles[i].Render(m);
		//マテリアルを無効
		mpMaterials[mTriangles[i].MaterialIdx()]->Disabled();
	}
}


