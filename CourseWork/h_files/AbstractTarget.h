#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

//#include "Shooter.h" он каким-то чудом знает о классе Shooter, хотя вроде не должен?!)
using namespace std;

struct Point
{
	int x = 0, y = 0;
};

class AbstractTarget
{
public:
	AbstractTarget();//Обычный конструктор, который никто никогда не должен создавать, кроме как для помещение объекта в мап\вектор
	AbstractTarget(const string& str);//Великолепные грабли, которые настроены на то, что мы создаём нормальный объект с индексом, а не пустышку
	~AbstractTarget();//Деструктор
	AbstractTarget(const AbstractTarget& other);//Конструктор копирования
	void CoutTarget() const;//Вывод мишени
	void CoutTarget(const vector<vector<char>>& other) const;//Вывод мишени при получении мишени напрямую
	int GetIndex() const;//Получить индекс текущей мишени
	int Shoot(int TargetNumber);//Выстрелить
	virtual int GetQuantityOfCurrTypes() const = 0;//Получить кол-во ВСЕХ-ВСЕХ мишеней определённого типа (метод виртуальный - переопределён)
	virtual int GetSize()const = 0;//Получить размер мишени
	virtual string GetType()const = 0;//Получить тип мишени
	int GetQuantityOfAllTypes()const;//Получить кол-во ВСЕХ-ВСЕХ мишеней ВСЕХ-ВСЕХ типов
protected:
	static int Count_of_AbstractTargets;//кол-во ВСЕХ-ВСЕХ мишеней
	static int StaticIndexCount;//Счётчик индексов
	int TargetIndex;//Текущий индекс
	Point CentrePoint;
	vector<vector<char>> Shape_Of_Figure;//Форма нашей мишени в двумерном массиве
	friend int GetNextIndex();//Грабли, потому-что не могу нормально вызвать int a = AbstractTarget::GetIndex { return StaticIndexCount; }
	friend class Shooter; //Я хотел сделать дружественным только один метод Shoot у класса Shooter, но компилято ругается, как бы я не пытался!! Опять грабли
};

int GetNextIndex();//Перед созданием эллемента, вызываем эту функцию и получаем индекс, который у неё будет. То есть, получаем следующий индекс, который будет после создания


