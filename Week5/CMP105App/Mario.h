#pragma once
#include"Framework/GameObject.h"
#include"Framework/Animation.h"
class Mario:public GameObject
{
public:
	float marioSpeed = 100.f;




	Mario();



	void update(float dt,Input*input);


public:
	Animation walk;
	Animation swim;
	Animation crouch;
	Animation idle;
	Animation* currentAnimation;

	
	
};

