#include "list.hpp"
#include <iostream>

void List::appendNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void List::insertNode(int val, int position) {
    Node* newNode = new Node;
    newNode->data = val;

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* nodePtr = head;
        for (int i = 1; i < position; i++) {
            nodePtr = nodePtr->next;
            if (nodePtr == head) {
                std::cout << "Position " << position << " not found in the list.\n";
                return;
            }
        }
        newNode->next = nodePtr->next;
        newNode->prev = nodePtr;
        nodePtr->next->prev = newNode;
        nodePtr->next = newNode;
    }
}

void List::deleteNode(int val) {
    if (!head) {
        std::cout << "Cannot Delete From An Empty List\n";
        return;
    }

    Node* nodePtr = head;
    do {
        if (nodePtr->data == val) {
            if (nodePtr == head) {
                head = head->next;
            }
            nodePtr->prev->next = nodePtr->next;
            nodePtr->next->prev = nodePtr->prev;
            delete nodePtr;
            return;
        }
        nodePtr = nodePtr->next;
    } while (nodePtr != head);

    std::cout << "Value " << val << " not found in the list.\n";
}

void List::displayList() const {
    Node* nodePtr = head;
    if (nodePtr) {
        do {
            std::cout << nodePtr->data << std::endl;
            nodePtr = nodePtr->next;
        } while (nodePtr != head);
    }
}