#include <iostream>
#include <tuple>
#include <vector>

/* Per side, iterate from the dividing mid index to determine the maximum 
 * subarray per side, then combine the two results for the maximum crossing
 * subarray. Maintain a current sum through the entirety of each side, caching
 * the index and sum of the largest subarray constructed. This action is linear 
 * as the crossing subarray with any elements must include a combination of the 
 * right end of a[low..mid] and the left end of a[mid+1..high]. */
template<typename T>
std::tuple<int, int, T> FindMaxCrossingSubarray(const std::vector<T>& a, int low, int mid, int high) {
	// Flags indicate the first sum comparison in place of a sentinel value
	bool left_flag{false};
	T sum{};
	int max_left{0};
	T left_sum = sum;
	for (int i = mid; i >= low; i--) {
		sum += a[i];
		if (sum > left_sum || !left_flag) {
			left_sum = sum;
			max_left = i;
			left_flag = true;
		}
	}

	bool right_flag{false};
	sum = {};
	int max_right = 0;
	T right_sum = sum;
	for (int j = mid + 1; j <= high; j++) {
		sum += a[j];
		if (sum > right_sum || !right_flag) {
			right_sum = sum;
			max_right = j;
			right_flag = true;
		}
	}
	return {max_left, max_right, left_sum + right_sum};
}

/* The maximum-subarray solution identifies the largest sum non-empty,
 * contiguous subarray. The maximum-subarray exists solely in three different
 * scenarios of the divide-and-conquer approach (array divided into [low..mid]
 * and [mid + 1..high]): entirely in subarray [low..mid], entirely in subarray
 * [mid+1..high], or crossing the midpoint (right end of [low..mid] and left end
 * of [mid + 1, high]). Divide the array into two until single element subarrays
 * remain, identify the maximum of the three scenarios, then return the result
 * up the call stack for comparisons between larger subarrays. Time complexity
 * O(nlgn). Space complexity O(1). */
template<typename T>
std::tuple<int, int, T> FindMaximumSubarray(const std::vector<T>& a, int low, int high) {
	if (high == low) {
		return {low, high, a[low]};	// base case: only one element
	}
	else {
		int mid = (low + high) / 2;
		int low_left, low_right, low_cross, high_left, high_right, high_cross;
		T sum_left, sum_right, sum_cross;
		std::tie(low_left, high_left, sum_left) = FindMaximumSubarray(a, low, mid);
		std::tie(low_right, high_right, sum_right) = FindMaximumSubarray(a, mid + 1, high);
		std::tie(low_cross, high_cross, sum_cross) = FindMaxCrossingSubarray(a, low, mid, high);
		if (sum_left >= sum_right && sum_left >= sum_cross) {
			return {low_left, high_left, sum_left};
		} else if (sum_right >= sum_left && sum_right >= sum_cross) {
			return {low_right, high_right, sum_right};
		} else {
			return {low_cross, high_cross, sum_cross};
		}
	}
}


int main() {
	std::vector<int> v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::tuple<size_t, size_t, int> r{FindMaximumSubarray(v, 0, static_cast<int>(v.size()) - 1)};
	std::cout << "low: " << std::get<0>(r) << std::endl;
	std::cout << "high: " << std::get<1>(r) << std::endl;
	std::cout << "sum: " << std::get<2>(r) << std::endl;
}