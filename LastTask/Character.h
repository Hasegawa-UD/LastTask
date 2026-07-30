#pragma once
#include <string>
#include "Action.h"

struct Character
{
protected:
	std::string _name; // キャラクターの名前
	int _attack;       // 攻撃力

public:
	Character(const std::string& name, int attack);
	virtual ~Character() = default; // 仮想デストラクタ

	// 仮想関数
	virtual Action chooseAction(bool isPlayerTurn) = 0;

	std::string getName() const; // 名前を取得する関数
	int getAttack() const;       // 攻撃力を取得する関数
};