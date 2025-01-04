#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &A, int n) {
	// assume first element is sorted
	for (int i = 1; i < n; i++) {
		// take next unsorted element in the arary
		int current = A[i];
		int j = i - 1;
		// loop backwards through sorted portion of the array
		// until we find the correct spot for the element
		while (j >= 0 && A[j] > current) {
			// move each larger element 1 spot to the right to make space
			// for the new element
			A[j + 1] = A[j];
			j--;
		}
		// put the element in the correct spot
		A[j + 1] = current;
	}
}

int main() {
	vector<int> nums = {5,2,4,6,1,3};
	insertion_sort(nums, nums.size());
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}
