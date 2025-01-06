#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<int> A) {
  for (int num : A) {
    cout << num << " ";
  }
  cout << endl;
}

void bubble_sort(vector<int> &A) {
  int n = A.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
      }
    }
  }
}

void insertion_sort(vector<int> &A, int n) {
  if (n == 0)
    return;
  // assume first element is sorted
  for (int i = 1; i < n; i++) {
    // value to be put into correct position
    int key = A[i];
    int j = i - 1;
    // find largest element that is smaller than key
    // key will go immediately after this element
    while (j >= 0 && key < A[j]) {
      // move every element that is larger than key 1 spot to the right
      // to make space for where key will go
      A[j + 1] = A[j];
      j--;
    }
    // put key in the correct position
    A[j + 1] = key;
  }
}

void selection_sort(vector<int> &A, int n) {
  if (n == 0)
    return;
  for (int i = 0; i < n - 1; i++) {
    // find smallest element that has not been sorted
    int smallest_value_index = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[smallest_value_index]) {
        smallest_value_index = j;
      }
    }
    // swap the smallest element with the element taking its spot
    swap(A[smallest_value_index], A[i]);
  }
}

void merge(vector<int> &A, int left, int right) {
  int middle = left + (right - left) / 2;
  assert(left <= middle && middle <= right);
  vector<int> temp(right - left + 1); // temp array for merging
  int l = left;                       // index for left array
  int r = middle + 1;                 // index for right array
  int j = 0;                          // index for temp array
  while (l <= middle && r <= right) {
    if (A[l] < A[r]) {
      temp[j] = A[l];
      l++;
    } else {
      temp[j] = A[r];
      r++;
    }
    j++;
  }
  // copy remaining left array elements
  while (l <= middle) {
    temp[j] = A[l];
    l++;
    j++;
  }
  // copy remaining right array elements
  while (r <= right) {
    temp[j] = A[r];
    r++;
    j++;
  }
  // copy temp array elements back to original array
  for (int i = 0; i < right - left + 1; i++) {
    A[i + left] = temp[i];
  }
}

void merge_sort_helper(vector<int> &A, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    merge_sort_helper(A, left, middle);
    merge_sort_helper(A, middle + 1, right);
    merge(A, left, right);
  }
}

void merge_sort(vector<int> &A, int n) {
  if (n == 0)
    return;
  merge_sort_helper(A, 0, n - 1);
}

void heapify(vector<int> &A, int idx, int n) {
  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  if (left < n && A[left] > A[largest])
    largest = left;
  if (right < n && A[right] > A[largest])
    largest = right;
  if (largest != idx) {
    swap(A[largest], A[idx]);
    heapify(A, largest, n);
  }
}

void heap_sort(vector<int> &A, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(A, i, A.size());
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(A[i], A[0]);
    heapify(A, 0, i);
  }
}

int main() {
  vector<int> nums = {7, 3, 1, 4, 2, 6, 5};
  // insertion_sort(nums, nums.size());
  // selection_sort(nums, nums.size());
  // merge_sort(nums, nums.size());
  // bubble_sort(nums);
  heap_sort(nums, nums.size());
  print_array(nums);
}
