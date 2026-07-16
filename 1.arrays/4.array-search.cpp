#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int needle) {
  for (int i = 0; i < size; i++)
    if (arr[i] == needle)
      return i;

  return -1;
}

int binarySearch(int arr[], int size, int needle) {
  int lo = 0;
  int hi = size - 1;

  while (lo <= hi) {
    /*
     * we could do (lo+ho) / 2 but instead we did  lo + (hi - lo) / 2, because
     * int data-types maximum value is 2^31. adding if an array has billions of
     * elements and adding lo which could be a really big number with another
     * big number hi, causes the value to "wrap around" to a negative
     * number, leading to an index out-of-bounds error or a crash.
     */
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] == needle) {
      return mid;
    } else if (needle < arr[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int element = 2;
  int searchIndex;
  searchIndex = binarySearch(arr, size, element);
  cout << "search index : " << searchIndex << endl;

  searchIndex = linearSearch(arr, size, 4);
  cout << "search index : " << searchIndex << endl;
}
