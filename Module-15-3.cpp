﻿/*Задача 3
Что нужно сделать
С клавиатуры вводятся числа. Когда пользователь вводит «-1»,
необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит «-2», программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы

Советы и рекомендации
Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел).*/
#include <iostream>
#include <vector>

int main()
{
	//инициализируем вектор 
	std::vector<int> userVector(0);
	//инициализируем переменную для ввода элемента вектора 
	int elements = 0;
	//инициализируем индекс для сортировки 
	size_t index = 0;

	//ввод первого элемента
	std::cout << "Input numbers: ";
	std::cin >> elements;

	//основной цикл продолжается пока не ввели -2
	while (elements != -2) {
		//если ввели -1 
		if (elements == -1) {
			//проверяем длинну вектора
			if (userVector.size() < 5) {
				//если меньше 5 выводим предупреждение
				std::cout << "There are still less than five elements in the array!" << std::endl;
			}
			else {
				//если больше или равно 5 выводим 5 по порядку элемент
				std::cout << "Five element: " << userVector[4] << std::endl;
			}
		}
		//если ввели новый элемент вектора
		else {
			//вставляем его в конец вектора
			userVector.push_back(elements);
			//устанавливаем индекс на новый элемент
			index = userVector.size() - 1;
			//двигаемего к началу на своё место по порядку
			while ((index > 0) && (userVector[index] < userVector[index - 1])) {
				std::swap(userVector[index], userVector[index - 1]);
				--index;
			}
		}
		//вывод отсортированного вектора
		for (int i = 0; i < userVector.size(); ++i)
		{
			std::cout << userVector[i] << " ";
		}
		std::cout << std::endl;
		//ввод следующего элемента
		std::cout << "Input numbers: ";
		std::cin >> elements;
	}
}