﻿#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#include "h_files/AbstractTarget.h"
#include "h_files/MyConverter.h"
#include "h_files/RoundTarget.h"
#include "h_files/HumanTarget.h"
#include "h_files/Shooter.h"
#include "h_files/ShootingGallery.h"

using namespace std;

//Варіант 6б.Створення ієрархії класів на тему «Стрільба по мішенях»
//Створити класи : «Абстрактна мішень»(поля - розміри мішені та двовимірний масив що описує мішень, методи «постріл», «координати центра»), підкласи «Кругла мішень», «Мішень у вигляді фігури людини».Використовувати двовимірний масив чисел, чи символів(за вибором студента).Метод постріл задає координати на мішені, а його результатом буде кількість балів, отримана стрілком.Метод координати цілі задає куди стріляти.Також створити можливість друкування мішені.Створити клас «Стрілок», який може викликати метод постріл для мішені.

int main()
{
	ShootingGallery MyShootingGallery;
	MyShootingGallery.Start();


	return 0;
}