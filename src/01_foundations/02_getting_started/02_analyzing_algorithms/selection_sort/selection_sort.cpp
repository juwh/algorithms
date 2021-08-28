#include <iostream>
#include <vector>

std::vector< int > SelectionSort(std::vector< int > a) {
    auto n = a.size();
    for (auto j = 0; j < n - 1; j++) {
        auto smallest = j;
        for (auto i = j + 1; i < n; i++) {
            if (a[i] < a[smallest]) {
                smallest = i;
            }
        }
        std::swap(a[j], a[smallest]);
    }
    return a;
}


int main() {
	std::vector< int > v{ 5, 2, 4, 6, 1, 3 };
	std::vector< int > v2 = SelectionSort(v);
	for (auto i = v.begin(); i != v.end(); i++) {
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
	for (auto j : v2) {
		std::cout << j << ' ';
	}
	std::cout << std::endl;
}