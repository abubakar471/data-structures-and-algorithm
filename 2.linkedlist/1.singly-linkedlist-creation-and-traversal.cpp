#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void show(Node *head) {
  Node *current = head;

  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }

  cout << endl;
}

int main() {
  Node *head = new Node();
  Node *sec_node = new Node();
  Node *third_node = new Node();

  head->data = 1;
  head->next = sec_node;
  sec_node->data = 2;
  sec_node->next = third_node;
  third_node->data = 3;
  third_node->next = nullptr;

  show(head);

  return 0;
}
