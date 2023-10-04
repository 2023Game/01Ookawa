#include "CModel.h"
#include <stdio.h>

void CModel::Load(char* obj, char* mtl)
{
	FILE* fp;
	char buf[256];

	fp = fopen(mtl, "r");
	if (fp == NULL) 
	{
		printf("%s file open errorÅèn", mtl);
		return;
	}

	while (fgets(buf, sizeof(buf), fp) != NULL) 
	{
		printf("%s", buf);
	}

	fclose(fp);

	fp = fopen(obj, "r");
	if (fp == NULL)
	{
		printf("%s file open errorÅèn", obj);
		return;
	}

	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		printf("%s", buf);
	}

	fclose(fp);
}
