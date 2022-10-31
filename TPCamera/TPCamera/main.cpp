#include<DxLib.h>
#include"Stage.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(FALSE);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(1920, 1080, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	SetLightDirection(VGet(0, 0, 1));

	SetCameraNearFar(1.0f, 500.0f);

	//(0,50,0)����(0,58,-20)������
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -20), VGet(0.0f, 0.0f, 0.0f));

	//�f�o�b�O�p
	Stage* stage = new Stage;

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		stage->Update(0.0f);
		stage->Draw();
		ScreenFlip();
	}


}