#pragma once
#include "AbstractTarget.h"

using namespace std;

struct Height {
	Height(const int& h);
	int height;
};

struct Width {
	explicit Width(const int& w);
	int width;
};

class HumanTargetSize
{
public:
	HumanTargetSize();
	HumanTargetSize(const Height& h, const Width& w);
	int GetHeight()const;
	int GetWidth()const;
private:
	int height;
	int width;
};

class HumanTarget : public AbstractTarget
{
public:
	int GetQuantityOfCurrTypes() const override;
	int GetSize() const override;
	string GetType() const override;
private:
	string type = "HumanTarget";
	static int Count_of_HumanTargets;
};
