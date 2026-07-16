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
    front = 0;
    rear = -1;
    arr = new T[capacity];
  }

  ~Queue() { delete[] arr; }

  bool isEmpty() { return front > rear; };
  bool isFull() { return rear == capacity - 1; }

  bool enqueue(T data) {
    if (isFull()) {
      cerr << "Queue Overflow" << endl;
      return false;
    } else {
      arr[++rear] = data;
      return true;
    }
  }

  bool dequeue(T &deqVal) {
    if (isEmpty()) {
      cerr << "Queue underflow" << endl;
      return false;
    } else {
      deqVal = arr[front++];
      return true;
    }
  }
};

int main() {
  Queue<int> *q = new Queue<int>(3);

  q->enqueue(1);
  q->enqueue(2);
  q->enqueue(3);

  int deqVal = 0;

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  };

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  };

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  };

  if (q->dequeue(deqVal)) {
    cout << deqVal << endl;
  };
}
