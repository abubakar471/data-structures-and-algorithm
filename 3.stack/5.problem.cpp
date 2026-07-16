
// evaluate postfix expression using stack

#include <functional>
#include <iostream>
#include <map>

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

  ~Stack() { delete[] arr; }

  bool isEmpty() { return top == -1; }
  bool isFull() { return top == capacity - 1; }

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

  bool peek(T &peekVal) {
    if (isEmpty()) {
      return false;
    }

    peekVal = arr[top];

    return true;
  }
};

bool isOperator(char ch) {
  return (ch == '/' || ch == '*' || ch == '+' || ch == '-');
}

int operatorKind(char ch) {
  if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
    return 2; // binary operator
  } else {
    return 1; // unary operator
  }
}

int main() {
  string postfix;

  cout << "enter the postfix expression: ";
  cin >> postfix;

  Stack<int> *stack = new Stack<int>((int)postfix.length());
  int peekVal = 0;
  int poppedVal = 0;

  map<char, function<int(int, int)>> operations;

  operations['+'] = [](int x, int y) { return x + y; };
  operations['-'] = [](int x, int y) { return x - y; };
  operations['*'] = [](int x, int y) { return x * y; };
  operations['/'] = [](int x, int y) { return x / y; };

  for (int i = 0; i < (int)postfix.length(); i++) {
    char c = postfix[i];

    if (!isOperator(c)) {
      // c - '0' subtracts the code for '0' so it converts the digit character
      // to its numeric value if c == '0' then c - '0' == 48 - 48 == 0 if c ==
      // '3' then c - '0' == 51 - 48 == 3
      stack->push(c - '0');
      stack->peek(peekVal);
    } else {
      int retVal = 0;

      if (operatorKind(c) == 2) {
        int operand1 = 0;
        int operand2 = 0;

        if (stack->pop(poppedVal)) {
          operand2 = poppedVal;
        }

        if (stack->pop(poppedVal)) {
          operand1 = poppedVal;
        }

        if (operations.count(c)) {
          retVal = operations[c](operand1, operand2);
          stack->push(retVal);
        }
      } else {
        int retVal = 0;
        if (stack->pop(poppedVal)) {
          retVal = operations[c](retVal, poppedVal);
          stack->push(retVal);
        }
      }
    }
  }

  if (stack->peek(peekVal)) {
    cout << "result is : " << peekVal << endl;
  };

  return 0;
}
