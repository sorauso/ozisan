#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class TestScene : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TestScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void UpScore(int up) { score_ += up; };
	void UpEsaNoKazu() { esaNoKazu_ += 1; };
	void DownEsaNoKazu() { esaNoKazu_ -= 1; };
private:
	Text* pText_;
	int score_;
	int esaNoKazu_;
};