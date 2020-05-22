#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

//Варіант 6б.Створення ієрархії класів на тему «Стрільба по мішенях»
//Створити класи : «Абстрактна мішень»(поля - розміри мішені та двовимірний масив що описує мішень, методи «постріл», «координати центра»), підкласи «Кругла мішень», «Мішень у вигляді фігури людини».Використовувати двовимірний масив чисел, чи символів(за вибором студента).Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.Метод координати цілі задає куди стріляти.Також створити можливість друкування мішені.Створити клас «Стрілок», який може викликати метод постріл для мішені.

struct Height {
	Height(int h) {
		height = h;
	}
	int height;
};

struct Width {
	explicit Width(int w) {
		width = w;
	}
	int width;
};

struct TargetSize {
	TargetSize() 
	{
		height = 10;
		width = 10;
	}
	TargetSize(Height h, Width w) {
		height = h.height;
		width = w.width;
	}
private:
	int height;
	int width;
};

class AbstractTarget
{	
protected:
	static int Count_of_AbstractTargets;
	TargetSize Target_Size;
	vector<vector<string>> Shape_Of_Figure;
	virtual void BuildTheTarget(void) = 0;
	int Shoot(int TargetNumber)
	{

	}
};

class RoundTarget : public AbstractTarget
{
public:
	RoundTarget() 
	{
		BuildTheTarget();
		Count_of_AbstractTargets++;
	}
	RoundTarget(TargetSize Target_Size)
	{
		BuildTheTarget();
		Count_of_AbstractTargets++;
		Count_of_RoundTargets++;
	}
	
private:
	static int Count_of_RoundTargets;
	virtual void BuildTheTarget(void) override
	{
		int x, y;

		cout << "Draw circle:\n\n";
		int circle_radius = 2.5;
		for (y = 0; y < 2 * circle_radius + 1; y++) {
			for (x = 0; x < 2 * circle_radius + 1; x++) {
				if ((int)hypot(abs(circle_radius - x), abs(circle_radius - y)) == circle_radius) { // Функция hypot вычисляет длину гипотенузы прямоугольного треугольника с заданной длиной двух сторон x и y.Вызов hypot эквивалентен следующему :sqrt(x*x + y*y);
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << "\n";
		}

		cout << "\n";
	}
};

class HumanTarget : public AbstractTarget
{
public:
	
private:
	static int Count_of_HumanTargets;
};

class Shooter
{
public:

};

void draw(void) {
	int x, y;

	cout << "Draw circle:\n\n";
	int circle_radius = 7;
	for (y = 0; y < 2 * circle_radius + 1; y++) {
		for (x = 0; x < 2 * circle_radius + 1; x++) {
			if ((int)hypot(abs(circle_radius - x), abs(circle_radius - y)) == circle_radius) { // Функция hypot вычисляет длину гипотенузы прямоугольного треугольника с заданной длиной двух сторон x и y.Вызов hypot эквивалентен следующему :sqrt(x*x + y*y);
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
}

int main()
{
	TargetSize testSize {
		Height(10),
		Width(20)
	};
	
	
	draw();
	
	return 0;
}
