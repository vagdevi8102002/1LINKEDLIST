#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void add(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* lastNode = head;
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
        }
    }
    void print() const {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
    void remove(int value) {
        Node* currentNode = head;
        Node* previousNode = nullptr;
        while (currentNode != nullptr) {
            if (currentNode->data == value) {
                if (previousNode == nullptr) {
                    head = currentNode->next;
                } else {
                    previousNode->next = currentNode->next;
                }
                delete currentNode;
                return;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
private:
    Node* head;
};

int main() {
    LinkedList myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.print(); // Output: 1 2 3
    myList.remove(2);
    myList.print(); // Output: 1 3
    return 0;
}

