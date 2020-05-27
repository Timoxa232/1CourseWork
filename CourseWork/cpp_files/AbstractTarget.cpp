#include "../h_files/AbstractTarget.h"
#include "../h_files/RoundTarget.h"
#include "../h_files/HumanTarget.h"

AbstractTarget::AbstractTarget()
{
	Count_of_AbstractTargets++;
	TargetIndex = -1;
}

AbstractTarget::AbstractTarget(const string& str)
{
	TargetIndex = StaticIndexCount;
	StaticIndexCount++;
	Count_of_AbstractTargets++;
}

AbstractTarget::~AbstractTarget()
{
	Count_of_AbstractTargets--;
}

AbstractTarget::AbstractTarget(const AbstractTarget& other)
{
	this->Shape_Of_Figure = other.Shape_Of_Figure;
	TargetIndex = other.GetIndex();
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

int AbstractTarget::GetQuantityOfAllTypes()const
{
	return Count_of_AbstractTargets;
}

int AbstractTarget::GetIndex() const
{
	return TargetIndex;
}

int AbstractTarget::Count_of_AbstractTargets = 0;

int AbstractTarget::StaticIndexCount = 0;

int GetNextIndex()
{
	return AbstractTarget::Count_of_AbstractTargets;
}
