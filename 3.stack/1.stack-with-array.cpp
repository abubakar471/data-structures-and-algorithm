#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
  int top;
  int capacity;
  T *arr;

  void grow() {
    capacity *= 2;
    T *newArr = new T[capacity];

    for (int i = 0; i <= top; i++) {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
  }

public:
  Stack(int cap = 20) {
    capacity = cap;
    top = -1;
    arr = new T[capacity];
  }

  ~Stack() {
    if (this->arr) {
      delete[] arr;
    }
  }

  bool isFull() { return this->top == capacity - 1; }
  bool isEmpty() { return this->top == -1; }

  bool push(T data) {
    if (isFull()) {
      // stack is full, grow the stack
      grow();
    }

    arr[++top] = data;

    return true;
  }

  bool pop(T &poppedVal) {
    if (isEmpty()) {
      throw underflow_error("stack is empty");
    } else {
      poppedVal = arr[top--];

      return true;
    }
  }

  T peek() {
    if (isEmpty()) {
      throw underflow_error("stack is empty");
    }

    return arr[top];
  }

  void destroy() {
    if (this->arr) {
      delete[] arr;
      top = -1;
    }
  }
};

int main() {
  Stack<string> *s = new Stack<string>(3);
  s->try {
    s->push("abu");
    s->push("bakar");
    s->push("siddique");

    cout << s->peek() << endl;
    string poppedVal;
    s->pop(poppedVal);
    cout << "Popped Value : " << poppedVal << endl;
  } catch (underflow_error e) {
    cout << e.what() << endl;
  }
}
