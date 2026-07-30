#pragma once
#include "Side.h"
#include <random>

class GameManager
{
private:
	Side _playerSide; // プレイヤーの陣営
	Side _enemySide;  // 敵の陣営
	std::mt19937 rnd; // 乱数生成

	// ターン処理
	void Turn();

	// 戦闘処理
	void BattleResult(Character* plaChara, Action plaAct, Character* eneChara, Action eneAct);

public:
	// コンストラクタ
	GameManager();

	// 初期化
	void GameStart();

	// バトル開始
	void BattleStart();
};

