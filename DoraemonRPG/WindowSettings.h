#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

struct WindowSettings
{
	WindowSettings();
	WindowSettings(std::string path);

	//Functions
	bool loadFromFile(std::string path);
	void saveToFile(std::string path);

	//Variables
	std::string title;
	sf::VideoMode resolution;
	int framerate;
	sf::ContextSettings contextSettings;
	bool vsync;

};

#endif // !WINDOWSETTINGS_H


