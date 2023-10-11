#include <iostream>
#include "list.hpp"

int main() {
    List list;
    int choice;
    int data;
    int position;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Append Node\n";
        std::cout << "2. Insert Node\n";
        std::cout << "3. Delete Node\n";
        std::cout << "4. Display List\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Data: ";
                std::cin >> data;
                list.appendNode(data);
                break;
            case 2:
                std::cout << "Enter Data: ";
                std::cin >> data;
                std::cout << "Enter Position: ";
                std::cin >> position;
                list.insertNode(data, position);
                break;
            case 3:
                std::cout << "Enter Data to Delete: ";
                std::cin >> data;
                list.deleteNode(data);
                break;
            case 4:
                std::cout << "List:\n";
                list.displayNode();
                break;
            case 5:
                std::cout << "Exiting program.";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}