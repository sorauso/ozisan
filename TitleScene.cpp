#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/sceneManager.h"

namespace
{
	bool isRode;
}

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

void TitleScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
	isRode = false;
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* sm = (SceneManager*)this->GetParent();
		sm->ChangeScene(SCENE_ID_TEST);
		isRode = true;
	}
}

void TitleScene::Draw()
{
	char drawText[255];
	if(isRode)
	{
		sprintf_s(drawText, "NOW LODING");
	}
	else
	{
		sprintf_s(drawText, "TITLE");
	}
	pText_->Draw(20, 20, drawText);
}

void TitleScene::Release()
{
}
