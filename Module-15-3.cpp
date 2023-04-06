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

void insert_heap(std::vector<int> vec) {
	return;
}

void print_vector(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	return;
}

int main()
{
	std::vector<int> userVector(1);
	int elements = 0;

	while (elements != -2) {
		std::cout << "Input numbers: ";
		std::cin >> elements;
		userVector.push_back(elements);
		insert_heap(userVector);
		print_vector(userVector);
	}
	
}