#include <iostream>
#include <vector>

/* Bubble sort repeatedly compared between adjacent elements and swaps if they
 * are out of order. Each iteration of the outer loop will move the smallest
 * element down to index i which represents the ith smallest element. Time
 * complexity O(n^2). Space complexity O(1). */
template<typename T>
std::vector<T> BubbleSort(std::vector<T> a) {
    // By bubble sorting up to the second to last element at index (n-2), the 
    // final element must be in the correct location
    for (size_t i = 0; i < a.size(); i++) {
        // The subarray [0-i) is sorted and does not require any swaps
        for (int j = static_cast<int>(a.size()) - 1; j >= static_cast<int>(i) + 1; j--) {
            if (a[j] < a[j-1]) {
                std::swap(a[j], a[j-1]);
            }
        }
    }
    return a;
}


int main() {
	std::vector< int > v{ 5, 2, 4, 6, 1, 3 };
	std::vector< int > v2 = BubbleSort(v);
	for (auto i = v.begin(); i != v.end(); i++) {
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
	for (auto j : v2) {
		std::cout << j << ' ';
	}
	std::cout << std::endl;
}