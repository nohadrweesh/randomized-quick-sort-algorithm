#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

/*int partition2(vector<int> &a, int l, int r) {
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

int* partition3(vector<int> &a, int l, int r) {
	int x = a[l];
	int j = l;
	int k = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < x) {
			j++;
			swap(a[i], a[j]);
		}
		else if (a[i] == x) {
			k++;
			swap(a[i], a[k]);
		}
	}
	swap(a[l], a[j]);
	int ret[] = { j + 1, k };
	return ret;
}*/
void partition(vector<int>&a, int l, int r, int&i, int&j){
	/*
	l:i-1---->   <x
	i:j------>   =x
	j+1:r---->   >x
	*/
	i = j = l;
	int x = a[l];
	for (int k = l + 1; k < a.size(); ++k){
		if (a[k] == x){
			//j++;
			swap(a[k], a[++j]);
		}
		else if (a[k] < x){
			swap(a[k], a[i++]);
			//i++;
			//j++;
			swap(a[k], a[++j]);

		}

	}


}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l);
	swap(a[l], a[k]);
		int i, j;
	partition(a, l, r, i, j);
	randomized_quick_sort3(a, l, i - 1);
	randomized_quick_sort3(a, j + 1, r);
}

/*void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m = partition2(a, l, r);

	randomized_quick_sort(a, l, m - 1);
	randomized_quick_sort(a, m + 1, r);
}*/

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort3(a, 0, a.size());
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
	system("pause");
}
