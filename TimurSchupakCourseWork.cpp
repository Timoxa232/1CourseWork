#include <iostream>
using namespace std;

//Варіант 6б.Створення ієрархії класів на тему «Стрільба по мішенях»
//Створити класи : «Абстрактна мішень»(поля - розміри мішені та двовимірний масив що описує мішень, методи «постріл», «координати центра»), підкласи «Кругла мішень», «Мішень у вигляді фігури людини».Використовувати двовимірний масив чисел, чи символів(за вибором студента).Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.Метод координати цілі задає куди стріляти.Також створити можливість друкування мішені.Створити клас «Стрілок», який може викликати метод постріл для мішені.

class AbstractTarget
{
public:
	virtual string Shoot(int x, int y)
	{

	}

private:
	static int Counts_of_AbstractTargets;
	int Target_Size;
	
};

class RoundTarget : public AbstractTarget
{
public:

private:
	static int Counts_of_RoundTargets;
};

class HumanTarget : public AbstractTarget
{
public:

private:
	static int Counts_of_HumanTargets;
};

int main()
{
	
}
