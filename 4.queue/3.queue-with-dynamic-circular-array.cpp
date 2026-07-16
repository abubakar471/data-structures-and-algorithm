#include <iostream>
using namespace std;

template <typename T> class Queue {
private:
  int front;
  int rear;
  int capacity;
  T *arr;

  void resize() {
    if (front > rear) {
      int size = capacity;
      capacity *= 2;
      T *newArr = new T[capacity];

      // 1. Shift the wrapped elements (from 0 up to rear) to the new extended
      // space
      for (int i = 0; i < front; i++) {
        newArr[i + size] = arr[i];
      }

      // 2. copy ALL remaining items from 'front' to the end of the old
      // array
      for (int i = front; i < size; i++) {
        newArr[i] = arr[i];
      }

      rear = rear + size;

      delete[] arr;
      arr = newArr;
    }

    if (front < rear) {
      capacity *= 2;
      T *newArr = new T[capacity];

      for (int i = front; i <= rear; i++) {
        newArr[i] = arr[i];
      }

      delete[] arr;
      arr = newArr;
    }
  }

public:
  Queue(int cap = 20) {
    capacity = cap;
    front = rear = -1;
    arr = new T[capacity];
  }

  ~Queue() { delete[] arr; }

  bool isEmpty() { return front == -1; }
  bool isFull() { return (rear + 1) % capacity == front; }

  bool enqueue(T data) {
    if (isFull()) {
      resize();
    }

    rear = (rear + 1) % capacity;

    if (front == -1) {
      front = rear;
    }

    arr[rear] = data;

    return true;
  }

  bool dequeue(T &deqVal) {
    if (isEmpty()) {
      cerr << "Queue underflow" << endl;
      return false;
    }

    deqVal = arr[front];

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }

    return true;
  }

  T getFront() { return front; }

  T getRear() { return rear; }
};

int main() {
  Queue<int> *q = new Queue<int>(4);

  int deqVal;

  q->enqueue(1);
  q->enqueue(2);
  q->enqueue(3);
  q->enqueue(4);

  q->dequeue(deqVal);
  q->dequeue(deqVal);
  q->dequeue(deqVal);

  cout << "current front: " << q->getFront() << endl;
  cout << "current rear: " << q->getRear() << endl;

  q->enqueue(5);
  q->enqueue(6);
  // after this insertion the queue will be full, if we do enque after that it
  // will grow the queue
  q->enqueue(7);

  cout << "current front: " << q->getFront() << endl;
  cout << "current rear: " << q->getRear() << endl;

  q->enqueue(8);

  cout << "current front: " << q->getFront() << endl;
  cout << "current rear: " << q->getRear() << endl;

  while (!q->isEmpty()) {
    if (q->dequeue(deqVal)) {
      cout << "dequeued value: " << deqVal << endl;
    }
  }
  return 0;
}
