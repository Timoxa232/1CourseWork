#include "../h_files/Shooter.h"

int Shooter::Shoot(const AbstractTarget& CurrTarget)
{
	return 1;
}

void Shooter::SetName(const string& name)
{
	this->name = name;
}

string Shooter::GetName() const
{
	return name;
}
