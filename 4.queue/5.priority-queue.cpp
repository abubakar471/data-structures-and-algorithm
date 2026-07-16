#include <iostream>
using namespace std;

template <typename T> struct Element {
  T data;
  int priority;
};

template <typename T> class Queue {
private:
  int front;
  int rear;
  int capacity;
  Element<T> *arr;

  void resize() {
    int size = capacity;
    capacity *= 2;
    Element<T> *newArr = new Element<T>[capacity];

    if (front > rear) {
      for (int i = 0; i < front; i++) {
        newArr[i + size] = arr[i];
      }

      for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
      }

      rear = rear + size;

      delete[] arr;
      arr = newArr;
    }

    if (front < rear) {
      for (int i = 0; i < capacity; i++) {
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
    arr = new Element<T>[capacity];
  }

  ~Queue() { delete[] arr; }

  bool isFull() { return (rear + 1) % capacity == front; }
  bool isEmpty() { return front == -1; }

  bool enqueue(T data, int priority) {
    if (isFull()) {
      resize();
    }

    Element<T> newElement = {data, priority};

    if (isEmpty()) {
      front = rear = 0;
      arr[rear] = newElement;

      return true;
    }

    rear = (rear + 1) % capacity;

    arr[rear] = newElement;

    /*
     * if our queue is like [{10, 4}, {11,3}, {4,2}] and we want to add
     * a new Element {3, 3} it will first check from rear position till position
     * not equal front to see if the current element's priority > previous
     * element priority , if true then it swap places with current and previous
     * element and swap places. if current element's priority is less than
     * previous element's priority then it breaks the loop as the array workins
     * in descending order. here it checks the previous element of current which
     * priority is 2 , in that case new element's priority is higher so swap
     * places and continue iterating till it reaches the position current !=
     * front or current's priority < previous's priority
     */

    int current = rear;
    while (current != front) {
      int prev = (current - 1 + capacity) % capacity;

      if (arr[current].priority > arr[prev].priority) {
        Element<T> temp = arr[current];
        arr[current] = arr[prev];
        arr[prev] = temp;
        current = prev;
      } else {
        break;
      }
    }

    return true;
  }

  bool dequeue(T &deqVal) {
    if (isEmpty()) {
      cerr << "Queue underflow" << endl;
      return false;
    }

    deqVal = arr[front].data;

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }

    return true;
  }
};

int main() {
  Queue<int> *q = new Queue<int>(3);

  q->enqueue(1, 2);
  q->enqueue(2, 1);
  q->enqueue(3, 2);

  int deqVal;

  while (!q->isEmpty()) {
    q->dequeue(deqVal);

    cout << deqVal << endl;
  }
}
