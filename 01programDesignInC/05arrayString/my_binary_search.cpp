#include <stdio.h>
#include <iostream>
using namespace std;

int my_binary_search(int target, int arr[], int n) {
  int start = 0, end = n - 1, mid = end / 2;
  while (start != end) {
    mid = (end - start) / 2 + start;
    if (target == arr[mid]) return mid;
    if (target < arr[mid]) {
      end = mid - 1;
    } else if (target > arr[mid]) {
      start = mid + 1;
    }
  }
  return target == arr[start] ? start : -1;
}

int main() {
  int target = 5;
  int arr[7] = {1, 3, 5, 7, 9, 10, 11};
  printf("target = 5, %d\n", my_binary_search(target, arr, 7));
  target = 1;
  printf("target = 1, %d\n", my_binary_search(target, arr, 7));
  target = 10;
  printf("target = 10, %d\n", my_binary_search(target, arr, 7));
  target = 11;
  printf("target = 11, %d\n", my_binary_search(target, arr, 7));
  int arr2[8] = {1, 3, 5, 7, 9, 10, 11, 12};
  printf("target = 5, %d\n", my_binary_search(target, arr2, 8));
  target = 1;
  printf("target = 1, %d\n", my_binary_search(target, arr2, 8));
  target = 10;
  printf("target = 10, %d\n", my_binary_search(target, arr2, 8));
  target = 11;
  printf("target = 11, %d\n", my_binary_search(target, arr2, 8));
  return 0;
}
