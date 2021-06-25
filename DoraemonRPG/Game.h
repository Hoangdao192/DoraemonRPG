#ifndef GAME_H
#define GAME_H

#include "WindowSettings.h"

class Game
{
private:
	//Variables

	//Window
	sf::RenderWindow window;
	WindowSettings windowSetting;
	sf::Event windowEvent;

	//Key
	std::map<std::string, int> supportedKeys;

	//Initializer
	void initVariables();
	void initSupportedKeys();
	void initWindow();

public:
	Game();
	~Game();

	void run();
};

#endif // !GAME_H



