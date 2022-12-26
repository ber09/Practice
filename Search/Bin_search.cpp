/*
 * Bin_search.cpp
 *
 *  Created on: 22 дек. 2022 г.
 *      Author: berezovskiy.v
 */

/*
 * Insertion_sort.cpp
 *
 *  Created on: 21 дек. 2022 г.
 *      Author: berezovskiy.v
 */
#include <iostream>
#include <ctime>

void init_mas(int *A, int size) {
	for (int i = 0; i < size; ++i) {
		*(A + i) = i;
	}
}

void print_mas(int *A, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(A + i) << " ";
	}
	std::cout << std::endl;
}

int bin_search(int *A, int right, int left, int target) {
	int middle = (right + left) / 2;

	if (*(A + middle) == target) {
		return middle + 1;
	}
	else if (target < *(A + middle)) {
		return bin_search(A, right, middle - 1, target);
	}
	else {
		return bin_search(A, middle + 1, left, target);
	}

	return -1;
}




int main(int argc, char **argv) {

	srand(time(NULL));

	int N, result, target;

	std::cout << "Введите размер массива" << "\n";
	std::cin >> N;

	std::cout << "Введите значение для поиска" << "\n";
	std::cin >> target;

	int *A = new int[N];

	init_mas(A, N);
	print_mas(A, N);

	result = bin_search(A, 0, N, target);

	if (result == -1) {
		std::cout << "Значение " << target << " отсутствует в массиве" << '\n';
	} else {
		std::cout << "Значение " << target
				<< " находится в ячейке под индексом " << result << '\n';
	}
	delete[] A;
	return 0;
}

