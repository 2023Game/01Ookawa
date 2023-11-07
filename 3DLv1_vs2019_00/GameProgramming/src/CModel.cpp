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
	}
}

void CModel::Load(char* obj, char* mtl)
{
	FILE* fp;
	char buf[256];
	std::vector<CVector> vertex;
	std::vector<CVector> normal;

	fp = fopen(mtl, "r");
	if (fp == NULL)
	{
		printf("%s file open error��n", mtl);
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
	}

	fclose(fp);

	fp = fopen(obj, "r");
	if (fp == NULL)
	{
		printf("%s file open error��n", obj);
		return;
	}

	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		char str[4][64] = { "", "", "", "" };
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);

		//�擪��v�̎��A���_�x�N�g�����쐬���Ēǉ�����
		if (strcmp(str[0], "v") == 0)
		{
			vertex.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}

		//�擪��f�̎��A�O�p�`���쐬���Ēǉ�����
		else if (strcmp(str[0], "f") == 0)
		{
			int v[3], n[3];
			sscanf(str[1], "%d//%d", &v[0], &n[0]);
			sscanf(str[2], "%d//%d", &v[1], &n[1]);
			sscanf(str[3], "%d//%d", &v[2], &n[2]);
			CTriangle t;
			t.Vertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
			t.Normal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
			t.MaterialIdx(idx);
			mTriangles.push_back(t);
		}

		//�擪��vn�̎��A�@���x�N�g�����쐬���Ēǉ�����
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

	}
	fclose(fp);

}

CModel::~CModel()
{
	printf("�ʉ߂P\n");
	for (int i = 0; i < mpMaterials.size(); i++)
	{
		printf("�ʉ߂Q\n");
		delete mpMaterials[i];
	}
}


