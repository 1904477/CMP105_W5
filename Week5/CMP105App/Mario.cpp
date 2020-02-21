#include "Mario.h"
Mario::Mario()
{
	idle.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.setFrameSpeed(1.f / 3.f);
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);
	crouch.addFrame(sf::IntRect(0, 41, 16, 20));
	crouch.addFrame(sf::IntRect(16, 41, 16, 20));
	crouch.setFrameSpeed(1.f / 4.f);
	currentAnimation = &idle;
	
	setTextureRect(currentAnimation->getCurrentFrame());
	}

void Mario::update(float dt, Input* input)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	
	if (input->isKeyDown(sf::Keyboard::L))
	{
		currentAnimation = &walk;
		marioSpeed = 100.f;
		move(marioSpeed * dt, 0);
		walk.setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());
	}


	else if (input->isKeyDown(sf::Keyboard::J))
	{
		currentAnimation = &walk;
		marioSpeed = 100.f;
		move(-marioSpeed * dt, 0);
		walk.setFlipped(true);
		setTextureRect(currentAnimation->getCurrentFrame());
		
	}
	
	else if (input->isKeyDown(sf::Keyboard::O))
	{
		currentAnimation = &swim;
		marioSpeed = 20;
		move(marioSpeed * dt, 0);
		swim.setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());
		
	}

	else if (input->isKeyDown(sf::Keyboard::U))
	{
		currentAnimation = &swim;
		marioSpeed = 20;
		move(-marioSpeed * dt, 0);
		swim.setFlipped(true);
		setTextureRect(currentAnimation->getCurrentFrame());
		
	}

	else if (input->isKeyDown(sf::Keyboard::K))
	{
		currentAnimation = &crouch;
		marioSpeed = 0;
		move(marioSpeed * dt, 0);
		swim.setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());
		currentAnimation=&idle;
	}
	else
	{
		currentAnimation->reset();
	}
}

