#include "stdafx.h"
#include "WindowSettings.h"


//Constructor
WindowSettings::WindowSettings()
{
	//Initializer variables with default values
	this->title = "UNKNOW";
	this->resolution.width = 1000;
	this->resolution.height = 562;
	this->framerate = 120;
	this->contextSettings.antialiasingLevel = 0;
	this->vsync = false;
}

WindowSettings::WindowSettings(std::string path)
{
	if (!this->loadFromFile(path))
	{
		//Init default values
		WindowSettings();
	}
}


//Functions
bool WindowSettings::loadFromFile(std::string path)
{
	std::fstream file(path, std::ios::in);
	if(!file.is_open())
	{ 
		writeLog("Error::Cannot load file " + path);
		return false;
	}
	file >> title;
	file >> resolution.width >> resolution.height;
	file >> framerate;
	file >> contextSettings.antialiasingLevel;
	file >> vsync;
	file.close();

	return true;
}

void WindowSettings::saveToFile(std::string path)
{
	std::fstream file(path, std::ios::out);
	file << title << std::endl;
	file << resolution.width << " " << resolution.height << std::endl;
	file << framerate << std::endl;
	file << contextSettings.antialiasingLevel << std::endl;
	file << vsync << std::endl;
	file.close();
}
