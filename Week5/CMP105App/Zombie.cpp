#include "Zombie.h"
Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	
}

void Zombie::update(float dt) 
{
	//walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
	
}

void Zombie::handleInput(float dt, Input* input)
{

	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.animate(dt);
		speed = 100.f;
		move(speed*dt,0);
		walk.setFlipped(false);
	}
	else if (input->isKeyDown(sf::Keyboard::A) == false)
	{
		walk.reset();
	}


	if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.animate(dt);
		speed = 100.f;
		move(-speed * dt, 0);
		walk.setFlipped(true);
	}
	
	
	else if (input->isKeyDown(sf::Keyboard::D) == false)
	{
		walk.reset();
	}
}