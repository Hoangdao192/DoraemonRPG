#include "stdafx.h"
#include "Game.h"

//Initializer

void Game::initVariables()
{
}

void Game::initSupportedKeys()
{
	std::fstream file("Config/supported_keys.ini", std::ios::in);
	if (!file.is_open())
	{
		writeLog("Error::Cannot load file Config/supported_keys.ini");
		supportedKeys["Escape"] = 36;
		return;
	}

	while (!file.eof())
	{
		std::string key_name;
		int key_value;
		file >> key_name >> key_value;
		supportedKeys[key_name] = key_value;
	}
	file.close();

	std::cout << "SUPPORTED KEYS LOADED\n";
	for (auto& i : supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}

}

void Game::initWindow()
{
	//Init windowSetting and create window
	this->windowSetting.loadFromFile("Config/window_setting.ini");

	this->window.create(windowSetting.resolution, windowSetting.title, sf::Style::Default, windowSetting.contextSettings);
}

//Constructor/Destructor

Game::Game()
{
	this->initWindow();
	this->initSupportedKeys();
}

Game::~Game()
{
}

//Functions

void Game::run()
{
	while (this->window.isOpen())
	{
		this->window.waitEvent(windowEvent);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || windowEvent.type == sf::Event::EventType::Closed)
		{
			this->window.close();
		}
	}
}
