#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
class AbstractTarget
{
public:
	AbstractTarget();
	~AbstractTarget();
	AbstractTarget(const AbstractTarget& other);
	void CoutTarget() const;
	int Shoot(int TargetNumber);
	int GetIndex() const;
	virtual int GetQuantityOfCurrTypes() const = 0;
	virtual int GetSize()const = 0;
	virtual string GetType()const = 0;
protected:
	int GetQuantityOfAllTypes();
	static int Count_of_AbstractTargets;
	int TargetIndex;
	vector<vector<char>> Shape_Of_Figure;
};

