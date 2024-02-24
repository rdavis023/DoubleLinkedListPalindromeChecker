#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~DoublyLinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "empty" << endl;
      return;
    }
    while (temp->next != nullptr) {
      cout << temp->value << " <-> ";
      temp = temp->next;
    }
    cout << temp->value << endl;
  }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  int getLength() { return length; }

  void append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This is the isPalindrome method.                  |
  //   | - It checks if the list is a palindrome or not.     |
  //   | - Return type: bool                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - A list with 0 or 1 node is a palindrome.          |
  //   | - Create two pointers: forwardNode and backwardNode.|
  //   | - Loop from the start to the middle of the list.    |
  //   | - Compare forwardNode and backwardNode values.      |
  //   | - If any pair is not equal, return false.           |
  //   | - Otherwise, return true.                           |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  bool isPalindrome() {
    // A list with 0 or 1 node is automatically a palindrome.
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    Node *forwardNode = head;
    Node *backwardNode = tail;

    // Calculate the midpoint of the list.
    int steps = length / 2;

    // Loop from the start to the middle of the list.
    for (int i = 0; i < steps; i++) {
      // Compare forwardNode and backwardNode values.
      if (forwardNode->value != backwardNode->value) {
        return false; // If any pair is not equal, the list is not a palindrome.
      }
      // Move forwardNode forward and backwardNode backward.
      forwardNode = forwardNode->next;
      backwardNode = backwardNode->prev;
    }

    // If the loop completes without finding any unequal pairs, the list is a
    // palindrome.
    return true;
  }
};
