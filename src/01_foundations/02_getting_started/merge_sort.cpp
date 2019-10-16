#include <iostream>
#include <vector>

void Merge(std::vector< int > &a, int p, int q, int r) {
	auto n1 = q - p + 1;
	auto n2 = r - q;
	std::vector< int > L;
	std::vector< int > R;
	auto i = 0;
	auto j = 0;
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
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
}

void MergeSort(std::vector< int > &a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
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