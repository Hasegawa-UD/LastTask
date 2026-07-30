#include "Party.h"
#include <random>

// ÉiÉCÉg
Knight::Knight(const std::string& name, int attack) : Character(name, attack)
{

}
Action Knight::chooseAction(bool isPlayerTurn)
{
	if (!isPlayerTurn)
	{
		static std::mt19937 rnd(std::random_device{}());
		std::uniform_int_distribution<int> dist(0, 1);
		return dist(rnd) == 0 ? Action(true, "çUåÇ") : Action(false, "ñhå‰");
	}

	return Action(false, "ñhå‰");
}

// ÉEÉBÉbÉ`
Witch::Witch(const std::string& name, int attack) : Character(name, attack)
{

}
Action Witch::chooseAction(bool isPlayerTurn)
{
	if (!isPlayerTurn)
	{
		static std::mt19937 rnd(std::random_device{}());
		std::uniform_int_distribution<int> dist(0, 1);
		return dist(rnd) == 0 ? Action(true, "çUåÇ") : Action(false, "ñhå‰");
	}
	return Action(false, "ñhå‰");
}

// ÉGÉîÉHÅ[ÉJÅ[
Evoker::Evoker(const std::string& name, int attack) : Character(name, attack)
{

}
Action Evoker::chooseAction(bool isPlayerTurn)
{
	if (!isPlayerTurn)
	{
		static std::mt19937 rnd(std::random_device{}());
		std::uniform_int_distribution<int> dist(0, 1);
		return dist(rnd) == 0 ? Action(true, "çUåÇ") : Action(false, "ñhå‰");
	}
	return Action(false, "ñhå‰");
}

