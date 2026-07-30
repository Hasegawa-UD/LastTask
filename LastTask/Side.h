#pragma once
#include <string>
#include "Character.h"

class Side
{
private:
	std::string _sideName; // 陣営の名前
	int _sidePower;        // 陣営の戦力

	static const int maxCharacters = 3; // 最大キャラクター数
	Character* members[maxCharacters];  // キャラクターの配列
	int memberCount;                    // 現在のキャラクター数

public:
	// コンストラクタ
	Side(const std::string& name, int power);
	
	// デストラクタ
	~Side();

	// キャラを追加する関数
	void addCharacter(Character* character);

	// ダメージ処理
	void takeDamage(int damage);

	// 敗北判定
	bool isLosed() const;

	// 戦力を取得する関数
	int getPower() const;

	// 陣営の名前を取得する関数
	std::string getName() const;

	// キャラクターの数を取得する関数
	int getMemberCount() const;

	// キャラクターを取得する関数
	Character* const getMember(int index) const;
};

