#pragma once

#include "AbstractTarget.h"
#include "MyConverter.h"
#include "RoundTarget.h"
#include "HumanTarget.h"
#include "Shooter.h"

using namespace std;

class ShootingGallery
{
public:
	void Start();
private:
	map<int, AbstractTarget*> map_AllTargets;
	map<int, RoundTarget> map_RoundTargets;
	map<int, HumanTarget> map_HumanTargets;
	Shooter currShooter;
	void MakeNewTarget();
	void DeleteTarget();
	void Shoot();
	void TargetsList();
	void TargetSizeInfo();
	void CoutTarget();
	void End();

};