#include "ResultScene.h"
#include "Engine/Input.h"
#include "Engine/sceneManager.h"

namespace
{
	bool isRode;
}

ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene")
{
}

void ResultScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
	isRode = false;
}

void ResultScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* sm = (SceneManager*)this->GetParent();
		sm->ChangeScene(SCENE_ID_TITLE);
		isRode = true;
	}
}

void ResultScene::Draw()
{
	char drawText[255];
	if (isRode)
	{
		sprintf_s(drawText, "NOW LODING");
	}
	else
	{
		sprintf_s(drawText, "RESULT");
	}
	pText_->Draw(20, 20, drawText);
}

void ResultScene::Release()
{
}
