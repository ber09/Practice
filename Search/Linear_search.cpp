/*
 * Linear_search.cpp
 *
 *  Created on: 22 дек. 2022 г.
 *      Author: berezovskiy.v
 */

#include <iostream>
#include <ctime>
#include <string>

void init_mas(int *A, int size) {
	for (int i = 0; i < size; ++i) {
		*(A + i) = rand() % 100;
	}
}

void print_mas(int *A, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(A + i) << " ";
	}
	std::cout << std::endl;
}

int linear_search(int *A, int size, int target) {
	for (int i = 0; i < size; ++i) {
		if (*(A + i) == target) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv) {

	srand(time(NULL));

	int N, target, result;

	std::cout << "Введите размер массива" << "\n";
	std::cin >> N;

	std::cout << "Введите значение для поиска" << "\n";
	std::cin >> target;

	int *A = new int[N];
	init_mas(A, N);
	print_mas(A, N);

	result = linear_search(A, N, target);

	if (result == -1) {
		std::cout << "Значение " << target << " Отсуствует" << std::endl;
	} else {
		std::cout << "Значение " << target << " находится под индексом "
				<< result << std::endl;
	}

	delete[] A;
	return 0;
}
