#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Engine/CsvReader.h"

#include "Box.h"
#include "Player.h"
#include "esa.h"
#include "TestScene.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent), hSilly(-1),mapWomdth(-1),mapHeight(-1)
{
	CsvReader csvData;
	csvData.Load("map.csv");
	mapWomdth = csvData.GetWidth();
	mapHeight = csvData.GetHeight();

	mapdata = std::vector<std::vector<int>>(mapHeight,std::vector<int>(mapWomdth,0));
	for (int y = 0;y < mapHeight;y++)
	{
		for (int x = 0;x < mapWomdth;x++)
		{
			mapdata[x][y] = csvData.GetValue(y, x);
		}
	}
}

void Ground::Initialize()
{
	hSilly = Model::Load("UVCheker.fbx");
	Model::SetAnimFrame(hSilly, 0, 59, 1.0);
	Instantiate<Player>(this);
	TestScene* tsesce = (TestScene*)this->GetParent();
	for (int z = 0;z < mapHeight;z++)
	{
		for (int x = 0;x < mapWomdth;x++)
		{
			if (mapdata[z][x] == 1)
			{
				Box* box = Instantiate<Box>(this);
				box->SetBoxPoint(x, z);
			}
			else if (mapdata[z][x] == 2)
			{
				Esa* esa = Instantiate<Esa>(this);
				esa->SetEsaPoint(x, z);
				esa->SetEsaType(ESA_TYPE_NORMAL);
				tsesce->UpEsaNoKazu();
			}
			else if (mapdata[z][x] == 3)
			{
				Esa* esa = Instantiate<Esa>(this);
				esa->SetEsaPoint(x, z);
				esa->SetEsaType(ESA_TYPE_POWER);
				tsesce->UpEsaNoKazu();
			}
		}
	}
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hSilly, transform_);
	Model::Draw(hSilly);
}

void Ground::Release()
{
}


int Ground::IsPointInBox(int x, int z)
{
	if (x >= mapdata.size() || x <= -1
		|| z >= mapdata.size() || z <= -1)
	{
		return 1;
	}
	int num = mapdata[z][x];
	return num;
}

int Ground::IsPositionInBox(XMFLOAT3 p)
{
	const float BOX_SCALE_SIZE = 3.34f;
	float pxF = p.x + BOX_SCALE_SIZE * 6;
	float pzF = (p.z * -1) + BOX_SCALE_SIZE * 6;
	int px = (pxF / BOX_SCALE_SIZE);
	int pz = (pzF / BOX_SCALE_SIZE);
	int num = IsPointInBox(px, pz);
	return num;
}
