#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Box.h"


//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	


	//pWp = Instantiate<Weapon>(this);
	Instantiate<Ground>(this);

	pText_ = new Text;
	pText_->Initialize();

}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
	char drawText[255];
	sprintf_s(drawText,"score:%d esa:%d",score_,esaNoKazu_);
	pText_->Draw(20, 20, drawText);
}

//開放
void TestScene::Release()
{
	pText_->Release();
}
