#pragma once
#include<vector>
#include"Stage.h"
#include"Meteor.h"
#include"Needle.h"
#include"Player.h"
#include"Aim.h"

class PlayScene
{
public:
	PlayScene();
	virtual ~PlayScene();
	void ALL();

private:
	Stage* stage = new Stage;
	Player* player = new Player();
	Aim* aim = new Aim();
	std::vector<ObstructBase*>obstructs;
	int nowTime;
	int previousTime;
	void Entry();
	VECTOR cell[4][4];
	unsigned int seed;
	float count;
	float obsCool;
	float deltaTime;
};

