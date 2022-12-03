#include<DxLib.h>
#include"Stage.h"
#include"Meteor.h"
#include"Needle.h"
#include"Player.h"
#include"Aim.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(FALSE);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetUseLighting(false);
	SetGraphMode(1920, 1080, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	/*SetLightDirection(VGet(0, 0, 1));
	SetLightPosition(VGet(0, 0, -30));*/
	

	SetCameraNearFar(1.0f, 490.0f);

	//(0,50,0)から(0,58,-20)を見る
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 0), VGet(0.0f, 0.0f, 250.0f));

	//デバッグ用
	Stage* stage = new Stage;
	Meteor* meteor = new Meteor(VGet(0, 0, 500), true);
	Needle* needle = new Needle(VGet(0, 0, 500));
	Player* player = new Player();
	Aim* aim = new Aim();



	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		stage->Update(0.0f);
		meteor->Update(0.16f);
		needle->Update(0.16f);
		player->Update(0.16f);
		aim->Update(0.16f,player->posGetter());
		stage->Draw();
		meteor->Draw();
		needle->Draw();
		aim->Draw(false);
		player->Draw();
		DrawFormatString(10, 10, GetColor(255, 255, 255), "x=%f y=%f", player->posGetter().x, player->posGetter().y);
		ScreenFlip();
	}


}