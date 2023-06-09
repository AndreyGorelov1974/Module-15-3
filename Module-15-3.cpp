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

//размер массива
const int sizeArray = 5;

int main()
{
	//инициализируем массив
	int arr[sizeArray]{};
	//инициализируем переменную для ввода элемента вектора 
	int element = 0;
	//инициализируем индекс для вставки элементов 
	int index = 0;

	//ввод первого элемента
	std::cout << "Input numbers: ";
	std::cin >> element;

	//основной цикл продолжается пока не ввели -2
	while (element != -2) {
		//если ввели -1 
		if (element == -1) {
			//проверяем количество знчащих элементов массива
			if (index < sizeArray) {
				//если меньше sizeArray выводим предупреждение
				std::cout << "There are still less than five elements in the array!" << std::endl;
			}
			else {
				//если больше или равно sizeArray выводим sizeArray по порядку элемент
				std::cout << "Five element: " << arr[sizeArray - 1] << std::endl;
			}
		}
		//если ввели новый элемент массива
		else {
			//если элементов меньше sizeArray вставляем за последним значащим элементом
			if (index < sizeArray) {
				arr[index] = element;
				++index;
				//инициализируем индекс для сортировки
				int indexSort = index - 1;
				//двигаемего к началу на своё место по порядку среди значащих элементов
				while ((indexSort > 0) && (arr[indexSort] < arr[indexSort - 1])) {
					std::swap(arr[indexSort], arr[indexSort - 1]);
					--indexSort;
				}
			}
			//если больше вставляем в конец массива
			else  if (arr[sizeArray - 1] >= element){
				arr[sizeArray - 1] = element;
				//инициализируем индекс для сортировки
				int indexSort = sizeArray - 1;
				//двигаемего к началу на своё место по порядку среди значащих элементов
				while ((indexSort > 0) && (arr[indexSort] < arr[indexSort - 1])) {
					std::swap(arr[indexSort], arr[indexSort - 1]);
					--indexSort;
				}
			}
		}
		//вывод отсортированного массива
		for (int i = 0; i < sizeArray; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		//ввод следующего элемента
		std::cout << "Input numbers: ";
		std::cin >> element;
	}
}