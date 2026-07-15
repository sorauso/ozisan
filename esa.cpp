#include "esa.h"
#include "Engine/Model.h"

Esa::Esa(GameObject* parent)
	:GameObject(parent), hDrawModel(-1)
{
}

void Esa::Initialize()
{
	hDrawModel = Model::Load("esa.fbx");
}

void Esa::Update()
{
}

void Esa::Draw()
{
	Model::SetTransform(hDrawModel, transform_);
	Model::Draw(hDrawModel);
}

void Esa::Release()
{

}

void Esa::SetEsaPoint(int x, int z)
{
	const float SCALE_SIZE = 3.34f;
	int pX = x - 6;
	int pZ = (z * -1) + 5;
	transform_.position_ = XMFLOAT3((pX * SCALE_SIZE) + SCALE_SIZE / 2, 1, (pZ * SCALE_SIZE) + SCALE_SIZE / 2);
}
