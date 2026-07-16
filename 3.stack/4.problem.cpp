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
  Stack(int cap) {
    capacity = cap;
    top = -1;
    arr = new T[capacity];
  }

  ~Stack() { delete[] arr; }

  bool isEmpty() { return top == -1; }
  bool isFull() { return top == capacity - 1; }

  bool peek(T &peekVal) {
    if (isEmpty()) {
      return false;
    }

    peekVal = arr[top];

    return true;
  }

  bool push(T data) {
    if (isFull()) {
      grow();
    }

    arr[++top] = data;

    return true;
  }

  bool pop(T &poppedVal) {
    if (isEmpty()) {
      return false;
    }

    poppedVal = arr[top--];

    return true;
  }
};

bool isOperator(char ch) {
  return (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' ||
          ch == ')');
}

int prec(char ch) {
  if (ch == '*' || ch == '/') {
    return 3;
  } else if (ch == '+' || ch == '-') {
    return 2;
  } else {
    return 1;
  }
}

int main() {
  string infix;
  string postfix;

  cout << "enter the infix exp (no spaces): ";
  cin >> infix;

  Stack<char> *stack = new Stack<char>((int)infix.length() / 2 + 1);

  char peekVal = '\0';
  char poppedVal = '\0';

  for (int i = 0; i < (int)infix.length(); i++) {
    char c = infix[i];

    if (!isOperator(c)) {
      postfix += c;
    } else if (c == ')') {
      while (!stack->isEmpty()) {
        if (stack->pop(poppedVal)) {
          stack->peek(peekVal);

          if (poppedVal != '(') {
            postfix += poppedVal;
          }
        }
      }

      if (stack->isEmpty()) {
        peekVal = '\0';
      }
    } else if (c == '(' || prec(c) > prec(peekVal)) {
      stack->push(c);
      stack->peek(peekVal);
    } else if (prec(c) <= prec(peekVal)) {
      if (stack->pop(poppedVal)) {
        if (poppedVal != '(') {
          postfix += poppedVal;
        }

        stack->push(c);
        stack->peek(peekVal);
      }
    }
  }

  while (!stack->isEmpty()) {
    if (stack->pop(poppedVal)) {
      if (poppedVal != '(') {
        postfix += poppedVal;
      }
    }
  }

  cout << "postfix expression : " << postfix << endl;

  return 0;
}
