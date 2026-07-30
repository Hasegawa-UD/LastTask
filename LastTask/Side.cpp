#include "Side.h"

// コンストラクタ
Side::Side(const std::string& name, int power)
{
	_sideName = name;
	_sidePower = power;
	memberCount = 0;

	// キャラクター配列を初期化
	for (int i = 0; i < maxCharacters; i++)
	{
		members[i] = nullptr;
	}
}

// デストラクタ
Side::~Side()
{
	// newで確保したメモリを解放
	for (int i = 0; i < memberCount; i++)
	{
		delete members[i];
		members[i] = nullptr;
	}
}

// キャラクターを追加する関数
void Side::addCharacter(Character* character)
{
	if (memberCount < maxCharacters)
	{
		members[memberCount] = character;
		memberCount++;
	}
}

// ダメージ処理
void Side::takeDamage(int damage)
{
	_sidePower -= damage;
	if (_sidePower < 0)
	{
		_sidePower = 0;
	}
}

// 敗北判定
bool Side::isLosed() const
{
	return _sidePower <= 0;
}

// 戦力を取得する関数
int Side::getPower() const
{
	return _sidePower;
}

// 陣営の名前を取得する関数
std::string Side::getName() const
{
	return _sideName;
}

// キャラクターの数を取得する関数
int Side::getMemberCount() const
{
	return memberCount;
}

// キャラクターを取得する関数
Character* const Side::getMember(int index) const
{
	if (index >= 0 && index < memberCount)
	{
		return members[index];
	}
	return nullptr;
}
