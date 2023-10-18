#include <iostream>
#include "list.hpp"

int main() {
    List myList;

    myList.appendNode(11);
    myList.appendNode(22);
    myList.appendNode(33);
    myList.appendNode(44);
    myList.appendNode(55);

    myList.displayList();

    List::Node* nodePtr = myList.head;
    if (nodePtr) {
        std::cout << "Node\tValue\tNext\tPrevious" << std::endl;
        int nodeNumber = 1;
        do {
            std::cout << nodeNumber << "\t" << nodePtr->data << "\t";

            if (nodePtr->next)
                std::cout << nodePtr->next->data << "\t";
            else
                std::cout << "N/A\t";

            if (nodePtr->prev)
                std::cout << nodePtr->prev->data << std::endl;
            else
                std::cout << "N/A" << std::endl;

            nodePtr = nodePtr->next;
            nodeNumber++;
        } while (nodePtr != myList.head);
    }

    return 0;
}
