#pragma once
#include<vector>
#include"Stage.h"
#include"Meteor.h"
#include"Needle.h"
#include"Player.h"
#include"Aim.h"
#include"Exprosion.h"

class PlayScene
{
public:
	PlayScene();
	virtual ~PlayScene();
	float ALL();
	int DeleteCountGetter() { return deleteCount; }

private:
	Stage* stage = new Stage;
	Player* player = new Player();
	Aim* aim = new Aim();
	std::vector<ObstructBase*>obstructs;
	std::vector<Exprosion*>expro;
	int nowTime;
	int previousTime;
	void Entry();
	void EntryExp(VECTOR _pos);
	void ObsDelete(ObstructBase* deleteObs);
	void ExpDelete(Exprosion* deleteExp);
	VECTOR cell[4][4];
	unsigned int seed;
	float count;
	float obsCool;
	float deltaTime;
	int deleteCount;
	float time;
};

