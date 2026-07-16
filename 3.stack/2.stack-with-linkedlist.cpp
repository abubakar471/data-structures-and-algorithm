#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node *next;

  Node(T data) {
    this->data = data;
    this->next = nullptr;
  }
};

// the actual linkedlist
template <typename T> class Stack {
private:
  int capacity;
  int count;
  Node<T> *top;

public:
  Stack(int cap = 20) {
    capacity = cap;
    count = 0;
    top = nullptr;
  }

  ~Stack() { deleteStack(); }

  bool isEmpty() { return top == nullptr; }

  bool isFull() { return count == capacity; }

  bool push(T data) {
    if (isFull()) {
      cerr << "Stack overflow" << endl;
      return false;
    }

    Node<T> *temp = new Node<T>(data);
    temp->next = top;
    top = temp;
    count++;

    return true;
  }

  bool pop() {
    if (isEmpty()) {
      cerr << "Stack underflow" << endl;
      return false;
    }

    Node<T> *temp = top;

    top = top->next;
    count--;

    delete temp;

    return true;
  }

  bool peek(T &data) {
    if (isEmpty()) {
      cerr << "Stack underflow" << endl;
      return false;
    }

    data = top->data;
    return true;
  }

  bool deleteStack() {
    Node<T> *current = top;
    Node<T> *temp = nullptr;

    while (current != nullptr) {
      temp = current;
      current = current->next;

      delete temp;
    }

    top = nullptr;
    count = 0;
    return true;
  }
};

int main() {
  Stack<int> *s = new Stack<int>(3);
  int topValue;

  if (s->peek(topValue)) {
    cout << "current top : " << topValue << endl;
  }

  s->push(1);
  s->push(2);
  s->push(3);

  if (s->peek(topValue)) {
    cout << "current top : " << topValue << endl;
  }

  s->pop();

  if (s->peek(topValue)) {
    cout << "current top : " << topValue << endl;
  }

  s->deleteStack();
}
