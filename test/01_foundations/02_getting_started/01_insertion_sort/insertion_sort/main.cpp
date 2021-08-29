#include <iostream>
#include <vector>

/* Insertion sort takes the first value beyond the "sorted" subarray, caching it
 * in a temporary variable, then shifts the sorted array until the value can be 
 * inserted in the appropriate location. As the value to be placed is cached,
 * shifting of elements a maximum of one place will only overwrite the cached 
 * spot. Time complexity O(n^2). Space complexity O(1). */
template<typename T>
std::vector<T> InsertionSort(std::vector<T> a) {
	// Start the sorted sequence as a single element in a[0]
	for (size_t j = 1; j < a.size(); j++) {
		// Cache the first element to be inserted at a[j]
		auto key = a[j];
		size_t i = j - 1; // i is the right end of sorted subarray
		// Shift the sorted subarray right one place, starting from the right 
		// end moving left until insertion spot
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		// Insert a[j] into the sorted sequence a[1..j-1(aka i)].
		a[i + 1] = key;
	}
	return a;
}

int main() {
	std::vector<int> v{ 5, 2, 4, 6, 1, 3 };
	std::vector<int> v2 = InsertionSort(v);
	for (auto i = v.begin(); i != v.end(); i++) {
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
	for (auto j : v2) {
		std::cout << j << ' ';
	}
	std::cout << std::endl;
}