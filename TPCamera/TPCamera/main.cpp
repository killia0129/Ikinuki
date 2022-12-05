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

	SetCameraNearFar(1.0f, 490.0f);

	//(0,50,0)����(0,58,-20)������
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 0), VGet(0.0f, 0.0f, 250.0f));

	//�f�o�b�O�p
	
	SetFontSize(30);

	while (loop)
	{
		TitleScene* titleScene = new TitleScene;

		score = titleScene->ALL();
		
		if (score == -2.0f)
		{
			break;
		}
		PlayScene* playScene = new PlayScene();
		score = playScene->ALL();
		if (score < 0.0f)
		{
			break;
		}
		delete playScene;
		while (!CheckHitKey(KEY_INPUT_SPACE))
		{
			ClearDrawScreen();
			DrawFormatString(800, 500, GetColor(255, 255, 255), "TIME :%f", score);
			DrawFormatString(900, 550, GetColor(255, 255, 255), "Press SPACE to Retry");
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