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
		*(A + i) = rand() % 100;
	}
}

void print_mas(int *A, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(A + i) << " ";
	}
	std::cout << std::endl;
}

void sort(int *A, int size, bool flag) {
	if (flag) {
		for (int i = 1; i < size; ++i) {
			int key = *(A + i);
			int j = i - 1;
			while (j >= 0 && *(A + j) > key) {
				*((A + j) + 1) = *(A + j);
				j = j - 1;
			}

			*((A + j) + 1) = key;
		}
	} else {
		for (int i = 1; i < size; ++i) {
			int key = *(A + i);
			int j = i - 1;
			while (j >= 0 && *(A + j) < key) {
				*((A + j) + 1) = *(A + j);
				j = j - 1;
			}

			*((A + j) + 1) = key;
		}
	}

}

int main(int argc, char **argv) {

	srand(time(NULL));

	int N;
	bool flag = false;
	std::cout << "Введите размер массива" << "\n";
	std::cin >> N;

	int *A = new int[N];
	init_mas(A, N);
	print_mas(A, N);

	sort(A, N, flag);
	print_mas(A, N);

	delete[] A;
	return 0;
}

