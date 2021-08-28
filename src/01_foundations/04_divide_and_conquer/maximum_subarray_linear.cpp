#include <iostream>
#include <vector>
#include <map>

std::map< std::string, int > FindMaximumSubarray(std::vector< int > a) {
	auto low = -1;
	auto high = -1;
	auto sum = 0;
	if (a.size() > 0) {
		sum = a[0];
		auto current_sum = 0;
		auto current_low = 0;
		for (int i = 0; i < a.size(); i++) {
			current_sum += a[i];
			if (current_sum > sum) {
				low = current_low;
				high = i;
				sum = current_sum;
			}
			if (current_sum < 0) {
				current_sum = 0;
				current_low = i + 1;
			}
		}
	}
	return std::map < std::string, int > {
		{ "low", low },
		{ "high", high },
		{ "sum", sum }
	};
}


int main() {
	std::vector< int > v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::map < std::string, int > r = FindMaximumSubarray(v);
	for (auto j : r) {
		std::cout << j.first << ' ' << j.second << std::endl;
	}
}