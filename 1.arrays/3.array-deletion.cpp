#include <iostream>
using namespace std;

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int sortedDeletion(int arr[], int index, int &size, int capacity) {
  if (size >= capacity || index < 0 || index > size) {
    return -1;
  }

  for (int i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }

  size--;

  return 1;
}

int unsortedDeletion(int arr[],int index, int &size, int capacity){
    if(size >= capacity || size < 0){
        return -1;
    }

    arr[index] = arr[size - 1];
    size--;
    return 1;
}

int main() {
  int capacity = 10;
  int size = 5;
  int index = 1;
  int arr[5] = {1, 2, 3, 4, 5};

  cout << "size : " << size << endl;
  display(arr, size);

  sortedDeletion(arr, index, size, capacity);
  cout << "size : " << size << endl;
  display(arr, size);

  unsortedDeletion(arr, index, size, capacity);
  cout << "size : " << size << endl;
  display(arr, size);
}
