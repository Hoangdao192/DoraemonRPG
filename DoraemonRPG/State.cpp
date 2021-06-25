#include "stdafx.h"
#include "State.h"


//Constructor/Destructor

State::State(sf::RenderWindow& window, std::map<std::string, State*>& states, std::map<std::string, int>& supportedKeys)
	:window(window), states(states), supportedKeys(supportedKeys)
{
	this->keyTimeMax = 50;
	this->clock.restart();
}

State::~State()
{
}

//Functions

bool State::getKeyTime()
{
	if (this->clock.getElapsedTime().asMilliseconds() >= keyTimeMax)
	{
		this->clock.restart();
		return true;
	}
	return false;
}