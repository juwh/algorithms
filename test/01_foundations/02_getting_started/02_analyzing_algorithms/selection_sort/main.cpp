#include <iostream>
#include <vector>

/* Selection sort identifies and selects next smallest/largest value in ordering
 * and swaps with the value at the next index of the sorted subarray. Time
 * complexity O(n^2). Space complexity O(1). */
template<typename T>
std::vector<T> SelectionSort(std::vector<T> a) {
    auto n = a.size();
    // By selecting and swapping the second to last element at index (n-2), the 
    // final element must be in the correct location
    for (size_t j = 0; j < n - 1; j++) {
        auto smallest = j;
        for (size_t i = j + 1; i < n; i++) {
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