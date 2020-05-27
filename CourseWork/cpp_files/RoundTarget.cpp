#include "../h_files/RoundTarget.h"

RoundTargetSize::RoundTargetSize()
{
	radius = 4.5;
}

RoundTargetSize::RoundTargetSize(const double& radius)
{
	this->radius = radius;
}

int RoundTargetSize::GetRadius() const
{
	return (int)radius;
}

RoundTarget::RoundTarget()
{
	BuildTheTarget();
}

RoundTarget::RoundTarget(const RoundTargetSize& target_size):AbstractTarget("with index")
{
	this->target_size = target_size;
	BuildTheTarget();
}

RoundTarget::~RoundTarget()
{
	Count_of_RoundTargets--;
}

RoundTarget::RoundTarget(const RoundTarget& other):AbstractTarget(other)
{
	this->target_size = other.target_size;
}

int RoundTarget::GetQuantityOfCurrTypes() const
{
	int ret = Count_of_RoundTargets;
	return ret;
}

int RoundTarget::GetSize() const
{
	return target_size.GetRadius();
}

string RoundTarget::GetType() const
{
	return type;
}

void RoundTarget::BuildTheTarget() {
	int circle_radius = target_size.GetRadius();
	for (int y = 0, x = 0, sizeX = 1, sizeY = 1; y < 2 * circle_radius + 1; y++) {
		Shape_Of_Figure.resize(sizeY);
		sizeY++;
		for (x = 0; x < 2 * circle_radius + 1; x++) {
			if ((int)hypot(abs(circle_radius - x), abs(circle_radius - y)) == circle_radius) { // Функция hypot вычисляет длину гипотенузы прямоугольного треугольника с заданной длиной двух сторон x и y.Вызов hypot эквивалентен следующему :sqrt(x*x + y*y);
				Shape_Of_Figure[y].resize(sizeX);
				sizeX++;
				Shape_Of_Figure[y][x] = '#';
			}
			else {
				Shape_Of_Figure[y].resize(sizeX);
				sizeX++;
				Shape_Of_Figure[y][x] = ' ';
			}
		}
		/*Shape_Of_Figure[y].resize(sizeX);
		Shape_Of_Figure[y][x] = '\n';*/
		sizeX = 1;
	}
	Count_of_RoundTargets++;
}

int RoundTarget::Count_of_RoundTargets = 0;