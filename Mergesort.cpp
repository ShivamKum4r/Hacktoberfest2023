#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
  // Create two temporary arrays to store the left and right subarrays
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  // Copy the left and right subarrays into the temporary arrays
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // Merge the two sorted subarrays back into the original array
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements from the temporary arrays into the original array
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point of the array
    int m = l + (r - l) / 2;

    // Recursively sort the left and right subarrays
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the two sorted subarrays
    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
