#include <iostream>
#include <vector>

template<typename T>
void Merge(std::vector<T> &a, int p, int q, int r) {
	// p is the start index, q is the middle index, r is the end index
	size_t n1 = q - p + 1; // Add one for middle index inclusive
	size_t n2 = r - q;
	std::vector< int > L;
	std::vector< int > R;
	size_t i = 0;
	size_t j = 0;
	// Populate left/right arrays to cache values when assigning back to the
	// result array a (by reference). This contributes to the O(n) space
	// complexity
	for (; i < n1; i++) {
		L.push_back(a[p + i]);
	}
	for (; j < n2; j++) {
		R.push_back(a[q + j + 1]);
	}
	i = 0;
	j = 0;
	for (int k = p; k <= r; k++) {
		if (j >= R.size() || (i < L.size() && L[i] <= R[j])) {
			// Upon reaching the end of the sorted right subsequence or
			// determining that the left subsequence front element is lowest, 
			// assign the value from the left subsequence and iterate to the
			// next lowest element of the left subsequence
			a[k] = L[i];
			i++;
		}
		else {
			// Otherwise either the left subsequence has been exhausted or the
			// right subsequence front element contains the lowest value, and
			// we apply actions from the right subsequence (assign to output
			// array, iterate to the next right subsequence value)
			a[k] = R[j];
			j++;
		}
	}
}

/* Merge sort divides the n-element sequence into two subsequences of n/2 
 * elements until each subsequence is of size 1. The merge function then
 * combines the split subsequences linearly with the invariant that the two
 * subsequences are sorted, allowing comparisons between only two values at the
 * front of each subsequence. Time complexity O(nlgn). Space complexity O(n). 
 * */
template<typename T>
void MergeSort(std::vector<T> &a, int p, int r) {
	// p is the start index, r is the end index
	if (p < r) {
		int q = (p + r) / 2;
		// Recursive calls to merge sort adjust the start/end boundaries until
		// they refer to single element subsequences that are then merged up
		MergeSort(a, p, q);
		MergeSort(a, q + 1, r);
		Merge(a, p, q, r);
	}
}


int main() {
	std::vector< int > v{ 5, 2, 4, 6, 1, 3 };
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	MergeSort(v, 0, v.size() - 1);
	for (auto j : v) {
		std::cout << j << ' ';
	}
	std::cout << std::endl;
}