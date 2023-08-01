#include "DxLib.h"
#include "Player.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//一部の関数はDxLib_Initの前に実行する必要がある
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
	{
		return -1;        // エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);


	//プレイヤーの初期化
	Player player;
	player.Init();

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();
		//描画を行う前に画面をクリアする
		ClearDrawScreen();
		//ゲームの処理

		player.Update();
		player.Draw();

		//画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		//FPSを60に設定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();            // ＤＸライブラリ使用の終了処理

	return 0;            // ソフトの終了
}