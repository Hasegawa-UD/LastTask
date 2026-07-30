#pragma once
#include "Character.h"

class Knight : public Character
{
public:
	Knight(const std::string& name, int attack);

	Action chooseAction(bool isPlayerTurn) override;
};

class Witch : public Character
{
public:
	Witch(const std::string& name, int attack);

	Action chooseAction(bool isPlayerTurn) override;
};

class Evoker : public Character
{
public:
	Evoker(const std::string& name, int attack);

	Action chooseAction(bool isPlayerTurn) override;
};

