/*
    key concept: Circular increment

    e.g. if we have an array arr[5] and we traverse from i = 0 and we increment
   i circularly, then we can use this formula i = (i + 1) % arrayLength from i =
   0, we increment circularly then i becomes i = (0+1) % 5 = 1 from i = 1, we
   increment circularly then i becomes i = (1+1) % 5 = 2 from i = 2, we
   increment circularly then i becomes i = (2+1) % 5 = 3 from i = 3, we
   increment circularly then i becomes i = (3+1) % 5 = 4 from i = 4, we
   increment circularly then i becomes i = (4+1) % 5 = 0

    see, we have gone to the first position after reaching last index of the
   array.

    we will use this concept in circular array to reset its front and rear index
   to -1 when it reaches the last of the array
*/

#include <iostream>
using namespace std;

template <typename T> class Queue {
private:
  int front;
  int rear;
  int capacity;
  T *arr;

public:
  Queue(int cap = 20) {
    capacity = cap;
    front = rear = -1;
    arr = new T[capacity];
  }

  ~Queue() { delete[] arr; }

  bool isEmpty() { return front == -1; }

  bool isFull() {
    return (rear + 1) % capacity == front;
    // return rear == capacity - 1;
  }

  int size() { return (capacity - (front + (rear + 1))) % capacity; }

  bool enque(T data) {
    if (isFull()) {
      cerr << "Queue overflow" << endl;
      return false;
    }

    rear = (rear + 1) % capacity;

    arr[rear] = data;

    if (front == -1) {
      front = rear;
    }

    return true;
  }

  bool dequeue(T &deqVal) {
    if (isEmpty()) {
      cerr << "Queue underflow" << endl;
      return false;
    }

    deqVal = arr[front];

    // that means we are removing the first element in that case we will set
    // front and rear to default index which is -1
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }

    return true;
  }
};

int main() {
  Queue<int> *q = new Queue<int>(2);

  q->enque(1);
  q->enque(2);

  int deqVal;

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  }

  q->enque(3);

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  }

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  }
  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  }
  return 0;
}
