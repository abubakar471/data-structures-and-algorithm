#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node *next;

  Node(T x) {
    data = x;
    next = nullptr;
  }
};

template <typename T> class Queue {
private:
  Node<T> *front;
  Node<T> *rear;
  int count;

public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool isEmpty() { return front == nullptr; }

  bool enqueue(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (front == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }

    count++;

    return true;
  }

  bool dequeue(T &deqVal) {
    if (isEmpty()) {
      cerr << "Queue underflow" << endl;
      return false;
    }

    deqVal = front->data;

    count--;

    if (front == rear) {
      delete front;

      front = rear = nullptr;

      return true;
    } else {
      Node<T> *temp = front;
      front = front->next;
      delete temp;

      return true;
    }
  }

  int size() { return count; }
};

int main() {
  Queue<int> *queue = new Queue<int>();

  int t;
  cout << "enter number of operations: ";
  cin >> t;

  while (t--) {
    int data;
    string ops;

    cout << "operation (insert x or delete) : ";
    cin >> ops;

    if (ops == "insert") {
      cin >> data;
      queue->enqueue(data);
    }

    if (ops == "delete") {
      int deqVal;

      if (queue->dequeue(deqVal)) {
        cout << "Deleted -> " << deqVal << endl;
      }
    }
  }
}
