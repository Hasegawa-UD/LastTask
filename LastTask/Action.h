#pragma once
#include <string>

struct Action
{
	bool _isAttack;     // true‚ÍUŒ‚, false‚Í–hŒä
	std::string _name;  // s“®‚Ì–¼‘O

	Action(bool isAttack = true, const std::string& name = "UŒ‚") 
	{
		_isAttack = isAttack;
		_name = name;
	}
};
