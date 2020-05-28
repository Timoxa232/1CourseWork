#pragma once
#include <string>
#include <vector>
#include "AbstractTarget.h"

using namespace std;

class Shooter
{
public:
	int Shoot(const AbstractTarget* CurrTarget, int shoot_x, int shoot_y);
	void SetName(const string& name);
	int GetPoint()const;
	string GetName() const;
private:
	int MyPoints = 0;
	string name;
};

