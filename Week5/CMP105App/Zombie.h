#pragma once
#include"Framework/GameObject.h"
#include"Framework/Animation.h"
class Zombie:public GameObject
{
public:
	Zombie();
	
	float speed = 100.f;

	void update(float dt) override;

	void handleInput(float dt, Input* input);

protected:
	Animation walk;


};

