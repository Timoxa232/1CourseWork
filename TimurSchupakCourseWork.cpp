#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

//Варіант 6б.Створення ієрархії класів на тему «Стрільба по мішенях»
//Створити класи : «Абстрактна мішень»(поля - розміри мішені та двовимірний масив що описує мішень, методи «постріл», «координати центра»), підкласи «Кругла мішень», «Мішень у вигляді фігури людини».Використовувати двовимірний масив чисел, чи символів(за вибором студента).Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.Метод координати цілі задає куди стріляти.Також створити можливість друкування мішені.Створити клас «Стрілок», який може викликати метод постріл для мішені.

class AbstractTarget
{	
public:
	AbstractTarget()
	{
		TargetIndex = Count_of_AbstractTargets;
		Count_of_AbstractTargets++;
	}
	void CoutTarget() const {
		for (vector<char> fir : Shape_Of_Figure) {
			for (char sec : fir) {
				cout << sec;
			}
			cout << endl;
		}
	}
	int Shoot(int TargetNumber)
	{

	}
	int GetQuantityOfAllTypes() const
	{
		return Count_of_AbstractTargets;
	}
	int GetIndex() const
	{
		return TargetIndex;
	}
	virtual int GetQuantityOfCurrTypes() const = 0;
protected:
	static int Count_of_AbstractTargets;
	int TargetIndex;
	vector<vector<char>> Shape_Of_Figure;
};


int AbstractTarget::Count_of_AbstractTargets = 0;

class RoundTargetSize
{
public:
	RoundTargetSize()
	{
		radius = 4.5;
	}
	RoundTargetSize(const double radius)
	{
		this->radius = radius;
	}
	int GetRadius() const
	{
		return radius;
	}
private:
	double radius;
};

class RoundTarget : public AbstractTarget
{
public:
	RoundTarget()
	{
		BuildTheTarget(target_size);
		//Count_of_AbstractTargets++; //вроде как можно не включать, если указать в дефолтном-абстракт-конструкторе 
		Count_of_RoundTargets++;
	}
	RoundTarget(const RoundTargetSize& target_size)
	{
		BuildTheTarget(target_size);
		//Count_of_AbstractTargets++;
		Count_of_RoundTargets++;
	}
	int GetQuantityOfCurrTypes() const override
	{
		return Count_of_RoundTargets;
	}
	
private:
	static int Count_of_RoundTargets;
	RoundTargetSize target_size;
	void BuildTheTarget(const RoundTargetSize& target_size) {
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
	}
	
};

int RoundTarget::Count_of_RoundTargets = 0;

struct Height {
	Height(const int& h) {
		height = h;
	}
	int height;
};

struct Width {
	explicit Width(const int& w) {
		width = w;
	}
	int width;
};

class HumanTargetSize
{
public:
	HumanTargetSize()
	{
		height = 10;
		width = 10;
	}
	HumanTargetSize(const Height& h, const Width& w) {
		height = h.height;
		width = w.width;
	}
	int GetHeight()const
	{
		return height;
	}
	int GetWidth()const
	{
		return width;
	}
private:
	int height;
	int width;
};

class HumanTarget : public AbstractTarget
{
public:
	int GetQuantityOfCurrTypes() const override
	{
		return Count_of_HumanTargets;
	}
private:
	static int Count_of_HumanTargets;
};

int HumanTarget::Count_of_HumanTargets = 0;

class Shooter
{
public:
	int Shoot(const AbstractTarget& CurrTarget)
	{
		return 1;
	}
};

class ShootingGallery
{
public:

private:

};





int main()
{
	RoundTarget test;
	RoundTarget test2(6);
	test.CoutTarget();

	Shooter asd;
	asd.Shoot(test);


	vector<AbstractTarget*>vec;
	vec.push_back(&test);
	vec.push_back(&test2);

	return 0;
}