#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	//initialise Zombie
	zombTexture.loadFromFile("gfx/animZombie.png");
	Zombie.setSize(sf::Vector2f(55, 110));
	Zombie.setPosition(100, 100);
	Zombie.setTexture(&zombTexture);
	// initialise game objects
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	Mario.setSize(sf::Vector2f(60, 84));
	Mario.setPosition(100, 400);
	Mario.setTexture(&marioTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	Zombie.handleInput(dt,input);
}

// Update game objects
void Level::update(float dt)
{
	Zombie.update(dt);
	Mario.update(dt,input);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Zombie);
	window->draw(Mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}