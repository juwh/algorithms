#include <iostream>
#include <vector>
#include <map>

std::map < std::string, int > FindMaxCrossingSubarray(std::vector< int > a, int low, int mid, int high) {
	auto left_flag = false;
	auto sum = 0;
	auto max_left = 0;
	auto left_sum = sum;
	for (auto i = mid; i >= low; i--) {
		sum += a[i];
		if (sum > left_sum || !left_flag) {
			left_sum = sum;
			max_left = i;
			left_flag = true;
		}
	}

	auto right_flag = false;
	sum = 0;
	auto max_right = 0;
	auto right_sum = sum;
	for (auto j = mid + 1; j <= high; j++) {
		sum += a[j];
		if (sum > right_sum || !right_flag) {
			right_sum = sum;
			max_right = j;
			right_flag = true;
		}
	}
	return std::map < std::string, int > { 
		{ "low", max_left }, 
		{ "high", max_right }, 
		{ "sum", left_sum + right_sum }
	};
}

std::map< std::string, int > FindMaximumSubarray(std::vector< int > a, int low, int high) {
	if (high == low) {
		return std::map < std::string, int > { 
			{ "low", low },
			{ "high", high },
			{ "sum", a[low] }
		};	// base case: only one element
	}
	else {
		auto mid = (low + high) / 2;
		std::map < std::string, int > left = FindMaximumSubarray(a, low, mid);
		std::map < std::string, int > right = FindMaximumSubarray(a, mid + 1, high);
		std::map < std::string, int > cross = FindMaxCrossingSubarray(a, low, mid, high);
		if (left["sum"] >= right["sum"] && left["sum"] >= cross["sum"]) {
			return std::map < std::string, int > {
				{ "low", left["low"] },
				{ "high", left["high"] },
				{ "sum", left["sum"] }
			};
		} else if (right["sum"] >= left["sum"] && right["sum"] >= cross["sum"]) {
			return std::map < std::string, int > {
				{ "low", right["low"] },
				{ "high", right["high"] },
				{ "sum", right["sum"] }
			};
		} else {
			return std::map < std::string, int > {
				{ "low", cross["low"] },
				{ "high", cross["high"] },
				{ "sum", cross["sum"] }
			};
		}
	}
}


int main() {
	std::vector< int > v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::map < std::string, int > r = FindMaximumSubarray(v, 0, v.size() - 1);
	for (auto j : r) {
		std::cout << j.first << ' ' << j.second << std::endl;
	}
}