#include <iostream>
#include <vector>
#include <map>

std::map< std::string, int > FindMaximumSubarray(std::vector< int > a) {
	if (a.size() > 0) {
		auto sum = a[0];
		auto minimum_idx = 0;
		auto minimum_sum = a[0];
		for (auto i = 1; i < a.size(); i++) {
			sum += a[i];
			if (sum < minimum_sum) {
				minimum_idx = i;
				minimum_sum = sum;
			}
		}
		minimum_idx++;
		sum = 0;
		auto maximum_idx = minimum_idx;
		auto maximum_sum = 0;
		for (auto j = maximum_idx; j < a.size(); j++) {
			sum += a[j];
			if (sum > maximum_sum) {
				maximum_idx = j;
				maximum_sum = sum;
			}
		}
		return std::map < std::string, int > {
			{ "low", minimum_idx },
			{ "high", maximum_idx },
			{ "sum", maximum_sum }
		};
	}
	return std::map < std::string, int > {
		{ "low", -1 },
		{ "high", -1 },
		{ "sum", 0 }
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