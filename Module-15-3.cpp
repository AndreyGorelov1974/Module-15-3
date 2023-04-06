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

int main()
{
	int vectorSize;
	std::cout << "Input vector size: ";
	std::cin >> vectorSize;
	std::vector<int> userVector(vectorSize);

	std::cout << "Input numbers: ";
	int elements = 0;

	for (int i = 0; i < userVector.size(); ++i)
	{
		std::cin >> elements;
		userVector[i] = elements;
	}

	std::cout << "Input number to delete: ";
	int deleteValue = 0;
	std::cin >> deleteValue;
	for (uint32_t i = 0; i < userVector.size(); ++i)
	{
		if (userVector[i] == deleteValue) {
			//при помощи обмена перемещаем элемент в конец вектора
			for (std::size_t j = i; j < userVector.size() - 1; ++j) {
				std::swap(userVector[j], userVector[j + 1]);
			}
			userVector.pop_back();
			//уменьшаем счётчик цикла что бы не пропустить следующий элемент
			--i;
		}
	}

	std::cout << "Result: ";
	for (int i = 0; i < userVector.size(); ++i)
	{
		std::cout << userVector[i] << " ";
	}

}