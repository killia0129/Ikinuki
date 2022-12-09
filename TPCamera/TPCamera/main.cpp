#include<DxLib.h>
#include "PlayScene.h"
#include"TitleScene.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(FALSE);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	SetUseLighting(false);
	SetGraphMode(1920, 1080, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	/*SetLightDirection(VGet(0, 0, 1));
	SetLightPosition(VGet(0, 0, -30));*/
	
	bool loop = true;
	float score = -1.0f;

	SetCameraNearFar(1.0f, 499.0f);

	//(0,50,0)����(0,58,-20)������
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 0), VGet(0.0f, 0.0f, 250.0f));

	//�f�o�b�O�p
	
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
				DrawFormatString(700, 450, GetColor(0, 255, 0), "CLEAR!");
				DrawFormatString(700, 500, GetColor(0, 255, 0), "TIME : %f seconds", score);
				DrawFormatString(800, 550, GetColor(0, 255, 0), "Press SPACE to Retry");
				
			}

			if (score < 0.0f)
			{
				DrawFormatString(600, 500, GetColor(0, 255, 0), "GAME OVER! %d Objects Remaining",30-deleted);
				DrawFormatString(800, 550, GetColor(0, 255, 0), "Press SPACE to Retry");
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