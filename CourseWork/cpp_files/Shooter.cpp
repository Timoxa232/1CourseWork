#include "../h_files/Shooter.h"

int Shooter::Shoot(const AbstractTarget* CurrTarget, int shoot_x, int shoot_y)
{
	int ret = 0;
	int y_axis = CurrTarget->Shape_Of_Figure.size()-1;
	int x_axis = CurrTarget->Shape_Of_Figure[0].size()-1;
	shoot_y = y_axis - shoot_y;
	if (shoot_y < 0 || shoot_x < 0 || shoot_y > y_axis || shoot_x > x_axis)
	{
		CurrTarget->CoutTarget();
		return ret;
	}

	vector<vector<char>>temp_Shape_Of_Figure = CurrTarget->Shape_Of_Figure;;
	temp_Shape_Of_Figure[shoot_y][shoot_x] = 'o';
	if (shoot_x == CurrTarget->CentrePoint.x  && shoot_y == CurrTarget->CentrePoint.y)
	{
		ret = 10;
	}
	else
	{
		if (temp_Shape_Of_Figure[shoot_y][shoot_x] == '#')
		{
			ret = 1;
		}
		else
		{
			int x = 0;
			char curr_symbol;
			short count_sharp_symbol = 0;
			while (x <= shoot_x)
			{
				curr_symbol = temp_Shape_Of_Figure[shoot_y][x];
				x++;
				if (curr_symbol == '#') count_sharp_symbol++;
			}

			if (count_sharp_symbol == 1)
			{
				ret = 5;
			}
		}
	}
	
	CurrTarget->CoutTarget(temp_Shape_Of_Figure);
	MyPoints += ret;
	return ret;
}

void Shooter::SetName(const string& name)
{
	this->name = name;
}

int Shooter::GetPoint() const
{
	return MyPoints;
}

string Shooter::GetName() const
{
	return name;
}
