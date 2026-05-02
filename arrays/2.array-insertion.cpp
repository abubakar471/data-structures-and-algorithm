#include <iostream>
using namespace std;

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int unsortedInsertion(int arr[], int &size, int element, int capacity,
                      int index) {
  if (size >= capacity) {
    return -1;
  }

  arr[size] = arr[index];
  arr[index] = element;
  size++;

  return 1;
}

// case 1: where you maintain the order of the array after insertion
int sortedInsertion(int arr[], int &size, int element, int capacity,
                    int index) {
  if (size >= capacity) {
    return -1;
  }

  for (int i = size; i >= index; i--) {
    arr[i] = arr[i - 1];
  }

  arr[index] = element;
  size++;

  return 1; // for successful insertion
}

int main() {
  int capacity = 100;
  int arr[5] = {1, 2, 3, 4, 5};
  int size = 5;
  int element = 45;
  int index = 3;
  int success = -1;

  cout << "size : " << size << endl;
  display(arr, size);
  success = sortedInsertion(arr, size, element, capacity, index);
  cout << "size : " << size << endl;

  if (success == 1)
    display(arr, size);

  success = unsortedInsertion(arr, size, 23, capacity, 2);
  cout << "size : " << size << endl;

  if (success == 1)
    display(arr, size);
}
