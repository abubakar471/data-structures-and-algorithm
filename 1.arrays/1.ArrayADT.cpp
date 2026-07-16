#include <iostream>
using namespace std;

class ArrayADT {
private:
  int *A;           // pointer to the array
  int totalSize;    // maximum capacity of the array
  int originalSize; // current number of elements in the array

public:
  ArrayADT(int s) {
    totalSize = s;
    originalSize = 0;
    A = new int[totalSize]; // heap allocation (pointer to the array, stored in
                            // the heap)
  }

  // destructor to free heap memory
  ~ArrayADT() { delete[] A; }

  // print the full array
  void show() {
    for (int i = 0; i < originalSize; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }

  int length() { return originalSize; }

  // add element at the end
  void append(int x) {
    if (originalSize < totalSize) {
      A[originalSize++] =
          x; // as we are using post-increment operator, so, when assigning x
             // originalSize is zero for the first element setting and then
             // originalSize gets incremented to 1
    }
  }

  void grow() {
    totalSize *= 2; // Double the capacity
    int *newA;
    newA = new int[totalSize];

    for (int i = 0; i < originalSize; i++) {
      newA[i] = A[i]; // Copy old data
    }

    delete[] A; // Free old memory
    A = newA;   // Point to new array
  }

  /*
  Summary: Reduces the capacity of the array when usage drops
  below a certain threshold to save memory.
  */
  void shrink() {
    // Only shrink if we are using 1/4 or less of the capacity
    // and the capacity is reasonably large (e.g., > 4)
    if (originalSize > 0 && originalSize <= totalSize / 4 && totalSize > 4) {
      totalSize /= 2;
      int *newA = new int[totalSize];

      for (int i = 0; i < originalSize; i++) {
        newA[i] = A[i];
      }

      delete[] A;
      A = newA;
    }
  }

  void insert(int index, int x) {
    if (originalSize == totalSize) {
      grow();
    }

    if (index >= 0 && index <= originalSize && originalSize < totalSize) {
      for (int i = originalSize; i > index; i--) {
        A[i] = A[i - 1];
      }

      A[index] = x;
      originalSize++;
    }
  }

  void remove(int index) {
    if (index >= 0 && index < originalSize) {
      for (int i = index; i < originalSize - 1; i++) {
        A[i] = A[i + 1];
      }
      originalSize--;

      // Check if we should reclaim memory
      shrink();
    } else {
      cerr << "OUT_OF_BOUNDS" << endl;
    }
  }

  int search(int needle) {
    for (int i = 0; i < originalSize; i++) {
      if (A[i] == needle) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  ArrayADT arr(3); // creating an array with the maximum capacity of 10 elements

  arr.append(1);
  arr.append(2);
  arr.show();

  arr.insert(1, 4);
  arr.show();

  arr.insert(1, 5);
  arr.show();

  arr.remove(2);
  arr.show();

  cout << arr.search(4) << endl;
  cout << arr.search(5) << endl;
}
