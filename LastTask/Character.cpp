#include "Character.h"

// コンストラクタ
Character::Character(const std::string& name, int attack)
{
	_name = name;
	_attack = attack;
}

// 名前を取得する関数
std::string Character::getName() const
{
	return _name;
}

// 攻撃力を取得する関数
int Character::getAttack() const
{
	return _attack;
}


