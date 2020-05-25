#pragma once
#include "AbstractTarget.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <math.h>
#include <map>

using namespace std;

class RoundTargetSize
{
public:
	RoundTargetSize();
	RoundTargetSize(const double& radius);
	int GetRadius() const;
private:
	double radius;
};

class RoundTarget : public AbstractTarget
{
public:
	RoundTarget();
	RoundTarget(const RoundTargetSize& target_size);
	~RoundTarget();
	RoundTarget(const RoundTarget& other);
	int GetQuantityOfCurrTypes() const override;
	int GetSize() const override;
	string GetType() const override;
private:
	static int Count_of_RoundTargets;
	string type = "RoundTarget";
	RoundTargetSize target_size;
	void BuildTheTarget();
};

