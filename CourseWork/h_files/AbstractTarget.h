#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

//#include "Shooter.h" �� �����-�� ����� ����� � ������ Shooter, ���� ����� �� ������?!)
using namespace std;

struct Point
{
	int x = 0, y = 0;
};

class AbstractTarget
{
public:
	AbstractTarget();//������� �����������, ������� ����� ������� �� ������ ���������, ����� ��� ��� ��������� ������� � ���\������
	AbstractTarget(const string& str);//������������ ������, ������� ��������� �� ��, ��� �� ������ ���������� ������ � ��������, � �� ��������
	~AbstractTarget();//����������
	AbstractTarget(const AbstractTarget& other);//����������� �����������
	void CoutTarget() const;//����� ������
	void CoutTarget(const vector<vector<char>>& other) const;//����� ������ ��� ��������� ������ ��������
	int GetIndex() const;//�������� ������ ������� ������
	int Shoot(int TargetNumber);//����������
	virtual int GetQuantityOfCurrTypes() const = 0;//�������� ���-�� ����-���� ������� ������������ ���� (����� ����������� - ������������)
	virtual int GetSize()const = 0;//�������� ������ ������
	virtual string GetType()const = 0;//�������� ��� ������
	int GetQuantityOfAllTypes()const;//�������� ���-�� ����-���� ������� ����-���� �����
protected:
	static int Count_of_AbstractTargets;//���-�� ����-���� �������
	static int StaticIndexCount;//������� ��������
	int TargetIndex;//������� ������
	Point CentrePoint;
	vector<vector<char>> Shape_Of_Figure;//����� ����� ������ � ��������� �������
	friend int GetNextIndex();//������, ������-��� �� ���� ��������� ������� int a = AbstractTarget::GetIndex { return StaticIndexCount; }
	friend class Shooter; //� ����� ������� ������������� ������ ���� ����� Shoot � ������ Shooter, �� ��������� ��������, ��� �� � �� �������!! ����� ������
};

int GetNextIndex();//����� ��������� ���������, �������� ��� ������� � �������� ������, ������� � �� �����. �� ����, �������� ��������� ������, ������� ����� ����� ��������


