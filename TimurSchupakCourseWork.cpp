#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

//Варіант 6б.Створення ієрархії класів на тему «Стрільба по мішенях»
//Створити класи : «Абстрактна мішень»(поля - розміри мішені та двовимірний масив що описує мішень, методи «постріл», «координати центра»), підкласи «Кругла мішень», «Мішень у вигляді фігури людини».Використовувати двовимірний масив чисел, чи символів(за вибором студента).Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.Метод координати цілі задає куди стріляти.Також створити можливість друкування мішені.Створити клас «Стрілок», який може викликати метод постріл для мішені.

bool ConvertStrToInt(const string& from, int& to)
{
	to = 0;
	char*  tmp = new char[100]{};
	char* p_tmp = tmp;
	for (const char& it : from) {
		if (it < '1' || it > '9') {
			delete p_tmp;
			//delete[] tmp;
			cout << "Fail type: \"" + from + "\" Try it again!";
			return false;
		}
		*tmp = it;
		tmp++;
	}
	to = atoi(p_tmp);
	//delete[] tmp;
	delete p_tmp;

	return true;
}

class AbstractTarget
{	
public:
	AbstractTarget()
	{
		TargetIndex = Count_of_AbstractTargets;
		Count_of_AbstractTargets++;
	}
	~AbstractTarget() {
		Count_of_AbstractTargets--;
	}
	AbstractTarget(const AbstractTarget& other)
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
	virtual int GetSize()const = 0;
	virtual string GetType()const = 0;
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
	RoundTargetSize(const double& radius)
	{
		this->radius = radius;
	}
	int GetRadius() const
	{
		return (int)radius;
	}
private:
	double radius;
};

class RoundTarget : public AbstractTarget
{
public:
	RoundTarget()
	{
		BuildTheTarget();
	}
	RoundTarget(const RoundTargetSize& target_size)
	{
		this->target_size = target_size;
		BuildTheTarget();
	}
	~RoundTarget()
	{
		Count_of_RoundTargets--;
	}
	RoundTarget(const RoundTarget& other)
	{
		Count_of_RoundTargets++;
	}
	int GetQuantityOfCurrTypes() const override
	{
		return Count_of_RoundTargets;
	}
	int GetSize() const override
	{
		return target_size.GetRadius();
	}
	string GetType() const override
	{
		return type;
	}
private:
	static int Count_of_RoundTargets;
	string type = "RoundTarget";
	RoundTargetSize target_size;
	void BuildTheTarget() {
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
	int GetSize() const override
	{
		return 1;
	}
	string GetType() const override
	{
		return type;
	}
private:
	string type = "HumanTarget";
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
	void SetName(const string& name)
	{
		this->name = name;
	}
	string GetName() const
	{
		return name;
	}
private:
	string name;
};

class ShootingGallery
{
public:
	void Start()
	{
		cout << "Welcome to My ShootingGallery simulator!" << endl;
		string command;
		do {
			cout << "Enter your's shooter name please: ";
			getline(cin, command);
		} while (command == "");
		currShooter.SetName(command);
		cout <<"Your name is: " << currShooter.GetName() << endl;
		while (true)
		{
			cout << "You have commands: MakeNewTarget, DeleteTarget, Shoot, TargetsList, TargetSizeInfo, CoutTarget, End. Enter it: ";
			cin >> command;
			if (command == "MakeNewTarget")
			{
				this->MakeNewTarget();
			}
			else if (command == "DeleteTarget")
			{

			}
			else if (command == "Shoot")
			{

			}
			else if (command == "TargetsList")
			{

			}
			else if (command == "TargetSizeInfo")
			{
				
			}
			else if (command == "CoutTarget")
			{

			}
			else if (command == "End")
			{
				break;
			}
			else
			{
				cout << "Unkonown command: \"" + command << "\" Try it again please!" << endl;
			}
		}
		this->End();
	}
private:
	map<int, AbstractTarget*> map_AllTargets;
	map<int, RoundTarget> map_RoundTargets;
	map<int, HumanTarget> map_HumanTargets;
	Shooter currShooter;
	void MakeNewTarget()
	{
		while (true)
		{
			cout << "What target-type you want? (RoundTarget, HumanTarget): ";
			string choice;
			cin >> choice;
			if (choice == "RoundTarget")
			{
				int tmp_size;
				do {
					cout << "Enter a RoundTarget size: ";
					cin >> choice;
				} while (ConvertStrToInt(choice, tmp_size) == false);

				RoundTarget tmp_target(tmp_size);
				map_RoundTargets[tmp_target.GetIndex()] = tmp_target;
				map_AllTargets[tmp_target.GetIndex()] = &map_RoundTargets[tmp_target.GetIndex()];
				cout << "Succesful! You make a target with index: " + to_string(tmp_target.GetIndex()) << endl;
				break;
			}
			else if (choice == "HumanTarget")
			{
				break;
			}
			else
			{
				cout << "Unkonown target-type: \"" + choice << "\" Try it again please!" << endl;
			}
		}

	}
	void Shoot()
	{
		string command;
		
	}
	void TargetsList()
	{
		cout << "We have: ";
		
	}
	void TargetSizeInfo()
	{
		string command;

	}
	void CoutTarget()
	{
		string command;

	}
	void End()
	{
		cout << "The end." << endl;
	}
};

int main()
{
	ShootingGallery MyShootingGallery;
	//MyShootingGallery.Start();

	cout << RoundTarget::GetQuantityOfAllTypes;

	return 0;
}