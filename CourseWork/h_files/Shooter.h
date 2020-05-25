#pragma once
#include <string>
#include "AbstractTarget.h"

using namespace std;

class Shooter
{
public:
	int Shoot(const AbstractTarget& CurrTarget);
	void SetName(const string& name);
	string GetName() const;
private:
	string name;
};

