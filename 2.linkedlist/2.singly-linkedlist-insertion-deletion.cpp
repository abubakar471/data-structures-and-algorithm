#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class linkedlist {
private:
  Node *head;

public:
  linkedlist() : head(nullptr) {};

  void insert(int index, int value) {
    if (index < 1) {
      cerr << "Invalid position" << endl;
    }

    // insert at beginning
    if (index == 1 || head == nullptr) {
      Node *newNode = new Node(value);
      newNode->next = head;
      head = newNode;

      return;
    }

    // insert at middle at any given position or even end
    int k = 1;
    Node *positionNode = head;

    while (k < index - 1 && positionNode != nullptr) {
      positionNode = positionNode->next;
      k++;
    }

    // position is larger than the list length
    if (positionNode == nullptr) {
      return;
    }

    Node *newNode = new Node(value);
    newNode->next = positionNode->next;
    positionNode->next = newNode;

    return;
  }

  void remove(int index) {
    if (index < 1 || head == nullptr) {
      cerr << "Invalid index" << endl;
      return;
    }

    Node *positionNode = nullptr;
    Node *current = head;
    int k = 1;

    while (k < index && current != nullptr) {
      positionNode = current;
      current = current->next;

      k++;
    }

    if (current == nullptr) {
      cerr << "Postion is larger than list length" << endl;
      return;
    }

    if (positionNode == nullptr) {
      // removing from beginning or the first node from the list
      head = current->next;
    } else {
      // removing from middle or end except beginning
      positionNode->next = current->next;
    }

    delete current;

    return;
  }

  void display() {
    Node *current = head;

    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }

    cout << endl;
  }
};

int main() {
  linkedlist list;

  for (int i = 1; i <= 5; i++) {
    list.insert(i, i);
  }

  list.display();

  list.remove(4);

  list.display();

  list.insert(3, 7);

  list.display();
}
