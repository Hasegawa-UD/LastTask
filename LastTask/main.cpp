#include <iostream>
#include "GameManager.h"

int main()
{
	// GameManagerのインスタンスを作成
	GameManager gameManager;

	// ゲームを初期化
	gameManager.GameStart();

	// バトルを開始
	gameManager.BattleStart();

	return 0;
}