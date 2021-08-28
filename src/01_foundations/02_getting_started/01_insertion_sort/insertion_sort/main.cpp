#include <iostream>
#include <vector>

std::vector< int > InsertionSort(std::vector< int > a) {
	size_t j = 1;
	for (; j < a.size(); j++) {
		auto key = a[j];
		// Insert A[j] into the sorted sequence A[1..j-1].
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	return a;
}

int main() {
	std::vector< int > v{ 5, 2, 4, 6, 1, 3 };
	std::vector< int > v2 = InsertionSort(v);
	for (auto i = v.begin(); i != v.end(); i++) {
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
	for (auto j : v2) {
		std::cout << j << ' ';
	}
	std::cout << std::endl;
}