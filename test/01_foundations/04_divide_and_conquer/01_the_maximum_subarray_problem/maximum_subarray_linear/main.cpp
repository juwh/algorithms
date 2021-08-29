#include <iostream>
#include <tuple>
#include <vector>

template<typename T>
std::tuple<int, int, T> FindMaximumSubarray(const std::vector<T>& a) {
	int low{-1};
	int high{-1};
	T sum{};
	if (a.size() > 0) {
		T current_sum{};
		int current_low{0};
		for (size_t i = 0; i < a.size(); i++) {
			current_sum += a[i];
			if (current_sum > sum) {
				low = current_low;
				high = i;
				sum = current_sum;
			}
			// If the current sum goes below zero, the accumulation of the next
			// maximum peak can begin from this point
			if (current_sum < 0) {
				current_sum = 0;
				current_low = i + 1;
			}
		}
	}
	return {low, high, sum};
}


int main() {
	std::vector<int> v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::tuple<int, int, int> r{FindMaximumSubarray(v)};
	std::cout << "low: " << std::get<0>(r) << std::endl;
	std::cout << "high: " << std::get<1>(r) << std::endl;
	std::cout << "sum: " << std::get<2>(r) << std::endl;
}