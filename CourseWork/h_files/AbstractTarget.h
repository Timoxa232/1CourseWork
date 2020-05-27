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
	AbstractTarget(const string& str);
	~AbstractTarget();
	AbstractTarget(const AbstractTarget& other);
	void CoutTarget() const;
	int Shoot(int TargetNumber);
	int GetIndex() const;
	virtual int GetQuantityOfCurrTypes() const = 0;
	virtual int GetSize()const = 0;
	virtual string GetType()const = 0;
	int GetQuantityOfAllTypes()const;
protected:
	static int Count_of_AbstractTargets;
	static int StaticIndexCount;
	int TargetIndex;
	vector<vector<char>> Shape_Of_Figure;
	friend int GetNextIndex();
};

int GetNextIndex();

