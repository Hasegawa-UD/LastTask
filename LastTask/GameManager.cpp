#include <iostream>
#include "GameManager.h"
#include "Party.h"

// コンストラクタ
GameManager::GameManager() : _playerSide("味方", 300), _enemySide("敵", 300), rnd(std::random_device{}())
{

}

int BattleCalculation(Character* defender, Character* attacker)
{
	std::string defenderName = defender->getName();
	std::string attackerName = attacker->getName();

	// 同じ役職同士の計算
	if((defenderName == "ナイト" && attackerName == "ナイト") || (defenderName == "ウィッチ" && attackerName == "ウィッチ") || (defenderName == "エヴォーカー" && attackerName == "エヴォーカー"))
	{
		return 0; // 何も起きない
	}

	// 攻撃側役職有利時の計算
	if((defenderName == "ナイト" && attackerName == "ウィッチ") || (defenderName == "ウィッチ" && attackerName == "エヴォーカー") || (defenderName == "エヴォーカー" && attackerName == "ナイト"))
	{
		return 2;
	}

	// 防御側役職有利時の計算
	if((defenderName == "ナイト" && attackerName == "エヴォーカー") || (defenderName == "ウィッチ" && attackerName == "ナイト") || (defenderName == "エヴォーカー" && attackerName == "ウィッチ"))
	{
		return 1;
	}
}


// 初期化
void GameManager::GameStart()
{
	// プレイヤーのキャラクターを new で追加
	_playerSide.addCharacter(new Knight("ナイト", 20));
	_playerSide.addCharacter(new Witch("ウィッチ", 30));
	_playerSide.addCharacter(new Evoker("エヴォーカー", 15));

	// 敵のキャラクターを new で追加
	_enemySide.addCharacter(new Knight("ナイト", 10));
	_enemySide.addCharacter(new Witch("ウィッチ", 15));
	_enemySide.addCharacter(new Evoker("エヴォーカー", 40));
}

void GameManager::BattleStart()
{
	std::cout << "======= 戦闘開始 =======" << std::endl << std::endl;

	int turnCount = 1;

	while (!_playerSide.isLosed() && !_enemySide.isLosed())
	{
		// ターン開始
		std::cout << "ターン(" << turnCount << ")" << std::endl;

		// 敵陣営の名前と現在の戦力の表示
		std::cout << "==== " << _enemySide.getName() << " ====" << std::endl;
		std::cout << "戦力(" << _enemySide.getPower() << ")" << std::endl;

		// 敵陣営の各キャラクターの名前と攻撃力を表示
		for (int i = 0; i < 3; i++)
		{
			Character* character = _enemySide.getMember(i);

			if (character != nullptr)
			{
				std::cout << character->getName() << std::endl;
				std::cout << "攻撃力：" << character->getAttack() << std::endl;
			}
		}

		// 味方陣営の名前と現在の戦力の表示
		std::cout << std::endl;
		std::cout << "==== " << _playerSide.getName() << " ====" << std::endl;
		std::cout << "戦力(" << _playerSide.getPower() << ")" << std::endl;

		// ターン処理
		Turn();
		turnCount++;
	}

	// 勝敗判定
	std::cout << "======= 戦闘終了 =======" << std::endl;

	if (_playerSide.isLosed() && _enemySide.isLosed())
	{
		std::cout << "引き分け" << std::endl;
	}
	else if (_playerSide.isLosed())
	{
		std::cout << _enemySide.getName() << "の勝利" << std::endl;
	}
	else
	{
		std::cout << _playerSide.getName() << "の勝利" << std::endl;
	}
}

// ターン処理
void GameManager::Turn()
{
	// 行動したいキャラの選択
	int playerCount = _playerSide.getMemberCount();

	std::cout << "行動するキャラクターを選択してください" << std::endl;
	for (int i = 0; i < playerCount; i++)
	{
		Character* character = _playerSide.getMember(i);

		if (character != nullptr)
		{
			std::cout << i + 1 << "：" << character->getName() << std::endl;
			std::cout << "攻撃力：" << character->getAttack() << std::endl;
		}
	}

	// プレイヤーの入力を取得
	int playerChoice = 0;
	std::cout << "> ";

	while (!(std::cin >> playerChoice) || playerChoice < 1 || playerChoice > playerCount)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "もう一度選択してください。" << std::endl;
	}
	Character* playerCharacter = _playerSide.getMember(playerChoice - 1);

	// 行動
	int playerActionChoice = 0;
	std::cout << "行動を選択してください (1: 攻撃, 2: 防御)" << std::endl;

	while ( !(std::cin >> playerActionChoice) || (playerActionChoice != 1 && playerActionChoice != 2))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "もう一度選択してください。 (1: 攻撃, 2: 防御)" << std::endl;
	}
	Action playerAction = (playerActionChoice == 1) ? Action(true, "攻撃") : Action(false, "防御");

	// 敵行動をランダムに選択
	int enemyCount = _enemySide.getMemberCount();

	int enemyIndex = rnd() % enemyCount;
	Character* enemyCharacter = _enemySide.getMember(enemyIndex);

	int enemyRndAction = rnd() % 2;
	Action enemyAction = (enemyRndAction == 0) ? Action(true, "攻撃") : Action(false, "防御");

	// 戦闘結果処理
	BattleResult(playerCharacter, playerAction, enemyCharacter, enemyAction);
}

void GameManager::BattleResult(Character* plaChara, Action plaAct, Character* eneChara, Action eneAct)
{
	std::cout << std::endl;
	std::cout << "======= 戦闘結果 =======" << std::endl;
	std::cout << "味方(" << plaChara->getName() << "("<<plaChara->getAttack() << "))   " << "行動(" << plaAct._name << ")" << std::endl;
	std::cout << "敵(" << eneChara->getName() << "("<<eneChara->getAttack() << "))   " << "行動(" << eneAct._name << ")" << std::endl;

	// 両者攻撃の場合
	if (plaAct._isAttack && eneAct._isAttack)
	{
		// プレイヤー攻撃力が敵攻撃力より大きい場合
		if (plaChara->getAttack() > eneChara->getAttack())
		{
			int damage = plaChara->getAttack();
			std::cout << plaChara->getName() << " の攻撃が貫通。敵に " << damage << " ダメージ。" << std::endl;
			_enemySide.takeDamage(damage);
		}
		// 敵攻撃力がプレイヤー攻撃力より大きい場合
		else if (eneChara->getAttack() > plaChara->getAttack())
		{
			int damage = eneChara->getAttack();
			std::cout << eneChara->getName() << " の攻撃が貫通。味方に " << damage << " ダメージ。" << std::endl;
			_playerSide.takeDamage(damage);
		}
		// 攻撃力が同じ場合
		else
		{
			std::cout << "攻撃力が一致。何も起きない。" << std::endl;
		}
	}

	// 味方が攻撃、敵が防御の場合
	else if (plaAct._isAttack && !eneAct._isAttack)
	{
		int result = BattleCalculation(eneChara, plaChara);

		if (result == 0)
		{
			std::cout << "両者同じ役職。攻撃を防がれた。" << std::endl;
		}
		else if (result == 2)
		{
			int damage = plaChara->getAttack() * 2;
			std::cout << plaChara->getName() << " の攻撃が貫通。敵に " << damage << " クリティカルダメージ。" << std::endl;
			_enemySide.takeDamage(damage);
		}
		else if (result == 1)
		{
			int damage = eneChara->getAttack() * 2;
			std::cout << eneChara->getName() << " が反撃。味方に " << damage << " クリティカルダメージ。" << std::endl;
			_playerSide.takeDamage(damage);
		}
	}
	// 味方が防御、敵が攻撃の場合
	else if (!plaAct._isAttack && eneAct._isAttack)
	{
		int result = BattleCalculation(plaChara, eneChara);

		if (result == 0)
		{
			std::cout << "両者同じ役職。攻撃を防いだ。" << std::endl;
		}
		else if (result == 2)
		{
			int damage = eneChara->getAttack() * 2;
			std::cout << eneChara->getName() << " の攻撃が貫通。味方に " << damage << " クリティカルダメージ。" << std::endl;
			_playerSide.takeDamage(damage);
		}
		else if (result == 1)
		{
			int damage = plaChara->getAttack() * 2;
			std::cout << plaChara->getName() << " が反撃。敵に " << damage << " クリティカルダメージ。" << std::endl;
			_enemySide.takeDamage(damage);
		}
	}
	// 両者防御の場合
	else
	{
		std::cout << "両者防御。何も起きない。" << std::endl;
	}

	std::cout << std::endl << std::endl;
}

