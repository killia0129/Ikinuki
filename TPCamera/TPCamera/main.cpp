#include<DxLib.h>
#include "PlayScene.h"
#include"TitleScene.h"


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
	
	bool loop = true;
	float score = -1.0f;

	SetCameraNearFar(1.0f, 499.0f);

	//(0,50,0)から(0,58,-20)を見る
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 0), VGet(0.0f, 0.0f, 250.0f));

	//デバッグ用
	
	LPCSTR font = "font/ARCADE.TTF";
	AddFontResourceEx(font, FR_PRIVATE, NULL);
	ChangeFont("Arcade", DX_CHARSET_DEFAULT);

	SetFontSize(40);

	while (loop)
	{
		TitleScene* titleScene = new TitleScene;

		score = titleScene->ALL();
		
		delete titleScene;

		if (score == -2.0f)
		{
			break;
		}
		PlayScene* playScene = new PlayScene();
		score = playScene->ALL();
		int deleted = playScene->DeleteCountGetter();
		if (score == -1.0f)
		{
			break;
		}
		delete playScene;
		while (!CheckHitKey(KEY_INPUT_SPACE))
		{
			ClearDrawScreen();
			if (score >= 0.0f)
			{
				SetFontSize(100);
				DrawFormatString(750, 400, GetColor(0, 255, 0), "CLEAR!");
				DrawFormatString(200, 500, GetColor(0, 255, 0), "TIME : %4.3f seconds", score);
				SetFontSize(50);
				DrawFormatString(600, 600, GetColor(0, 255, 0), "Press SPACE to Retry");
				SetFontSize(40);
			}

			if (score < 0.0f)
			{
				SetFontSize(100);
				DrawFormatString(300, 500, GetColor(0, 255, 0), "GAME OVER! %d Objects Remaining",30-deleted);
				SetFontSize(50);
				DrawFormatString(800, 600, GetColor(0, 255, 0), "Press SPACE to Retry");
				SetFontSize(40);
			}

			if (CheckHitKey(KEY_INPUT_ESCAPE))
			{
				loop = false;
				break;
			}
			ScreenFlip();
		}
		score = -1.0f;
	}

	



	DxLib_End();
	return 0;
}