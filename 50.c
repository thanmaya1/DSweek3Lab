#include <stdio.h>

// Swap two values
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition array around pivot
int partition(int arr[], int low, int high) {
  int pivotIndex = low;
  int pivotValue = arr[pivotIndex];
  swap(&arr[pivotIndex], &arr[high]);
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivotValue) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

// Main function
int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}

