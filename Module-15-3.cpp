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


int main()
{
	std::vector<int> userVector(0);
	int elements = 0;
	int index = 0;

	std::cout << "Input numbers: ";
	std::cin >> elements;

	while (elements != -2) {
		if (elements == -1) {
			std::cout << "Five element: " << userVector[4] << std::endl;
		}
		else {
			userVector.push_back(elements);
			index = userVector.size() - 1;
			while ((index > 0) && (userVector[index] < userVector[index - 1])) {
				std::swap(userVector[index], userVector[index - 1]);
				--index;
			}
		}
		for (int i = 0; i < userVector.size(); ++i)
		{
			std::cout << userVector[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Input numbers: ";
		std::cin >> elements;
	}

}