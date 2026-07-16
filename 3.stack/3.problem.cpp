// checking balancing of symbols with stack

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
  int capacity;
  int top;
  T *arr;

  void grow()
  {
    capacity *= 2;
    T *newArr = new T[capacity];

    for (int i = 0; i <= top; i++)
    {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
  }

public:
  Stack(int cap)
  {
    capacity = cap;
    top = -1;
    arr = new T[capacity];
  }

  ~Stack() { delete[] arr; }

  bool isEmpty() { return this->top == -1; }
  bool isFull() { return this->top == capacity - 1; }

  bool push(T data)
  {
    if (isFull())
    {
      grow();
    }

    arr[++top] = data;

    return true;
  }

  bool pop()
  {
    if (isEmpty())
    {
      cerr << "stack underflow" << endl;
      return false;
    }

    arr[top--];

    return true;
  }

  bool peek(T &data)
  {
    if (isEmpty())
    {
      return false;
    }
    else
    {
      data = arr[top];

      return true;
    }
  }
};

int main()
{
  string input;

  cout << "enter your sequence: ";
  cin >> input;

  bool isValid = true;

  Stack<char> *stack = new Stack<char>((int)input.length() / 2 + 1);
  char top;

  for (int i = 0; i < (int)input.length() && isValid; i++)
  {
    switch (input[i])
    {
    case '(':
    case '{':
    case '[':
      stack->push(input[i]);
      break;

    case ')':
    case '}':
    case ']':
    {
      // Use {} to create a local block scope for 'expected' variable.
      // Without it, variables declared in switch cases leak into other cases.
      if (stack->isEmpty() || !stack->peek(top))
      {
        isValid = false;
        break;
      }

      char expected = (input[i] == ')') ? '(' : (input[i] == '}') ? '{'
                                                                  : '[';

      if (top == expected)
      {
        stack->pop();
      }
      else
      {
        isValid = false;
      }
      break;
    }

    default:
      break;
    }
  }

  if (isValid && stack->isEmpty())
  {
    cout << "The sequence is valid" << endl;
  }
  else
  {
    cout << "The sequence is not valid" << endl;
  }

  delete stack;
  return 0;
}
