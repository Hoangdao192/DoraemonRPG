#ifndef STATE_H
#define STATE_H

class State
{
private:
	//Variables
	std::map<std::string, State*>& states;

	//Window
	sf::RenderWindow& window;

	//Key
	std::map<std::string, int>& supportedKeys;
	std::map<std::string, std::string> keyBinds;
	//KeyTime - time interval between two key presses
	sf::Clock clock;	//Count time
	int keyTimeMax;	//Miliseconds

	//Initializer
	virtual void initKeyBinds() = 0;

public:
	State(sf::RenderWindow& window, std::map<std::string, State*>& states, std::map<std::string, int>& supportedKeys);
	~State();

	//Functions
	bool getKeyTime();
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif // !STATE_H

