/*Задача 3
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
#include <algorithm>

void print_vector(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return;
}

int main()
{
	std::vector<int> userVector(0);
	int elements = 0;

	std::cout << "Input numbers: ";
	std::cin >> elements;

	while (elements != -2) {
		userVector.push_back(elements);
		std::sort(userVector.begin(), userVector.end());
		print_vector(userVector);
		std::cout << "Input numbers: ";
		std::cin >> elements;
	}
	
}