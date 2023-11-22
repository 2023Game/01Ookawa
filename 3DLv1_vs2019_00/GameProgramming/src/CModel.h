#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"

#ifndef CMODEL_H
#define CMODEL_H

class CModel 
{
public:
	~CModel();
	void Load(char* obj, char* mtl);
	void Render();
	void Render(const CMatrix& m);
private:
	std::vector<CTriangle> mTriangles;
	std::vector<CMaterial*> mpMaterials;
};

#endif

