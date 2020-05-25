#include "../h_files/AbstractTarget.h"
#include "../h_files/RoundTarget.h"
#include "../h_files/HumanTarget.h"

AbstractTarget::AbstractTarget()
{
	TargetIndex = Count_of_AbstractTargets;
	Count_of_AbstractTargets++;
}

AbstractTarget::~AbstractTarget()
{
	Count_of_AbstractTargets--;
}

AbstractTarget::AbstractTarget(const AbstractTarget& other)
{
	TargetIndex = Count_of_AbstractTargets;
	Count_of_AbstractTargets++;
}

void AbstractTarget::CoutTarget() const
{
	for (vector<char> fir : Shape_Of_Figure) {
		for (char sec : fir) {
			cout << sec;
		}
		cout << endl;
	}
}

int AbstractTarget::Shoot(int TargetNumber)
{
	return 0;
}

int AbstractTarget::GetQuantityOfAllTypes()
{
	int ret = Count_of_AbstractTargets;
	return ret;
}

int AbstractTarget::GetIndex() const
{
	return TargetIndex;
}

int AbstractTarget::Count_of_AbstractTargets = 0;

