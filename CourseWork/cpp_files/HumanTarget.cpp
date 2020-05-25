#include "../h_files/HumanTarget.h"

Height::Height(const int& h) {
	height = h;
}

Width::Width(const int& w) {
	width = w;
}

inline HumanTargetSize::HumanTargetSize()
{
	height = 10;
	width = 10;
}

inline HumanTargetSize::HumanTargetSize(const Height& h, const Width& w) {
	height = h.height;
	width = w.width;
}

inline int HumanTargetSize::GetHeight() const
{
	return height;
}

inline int HumanTargetSize::GetWidth() const
{
	return width;
}

inline int HumanTarget::GetQuantityOfCurrTypes() const
{
	return Count_of_HumanTargets;
}

inline int HumanTarget::GetSize() const
{
	return 1;
}

inline string HumanTarget::GetType() const
{
	return type;
}

int HumanTarget::Count_of_HumanTargets = 0;
