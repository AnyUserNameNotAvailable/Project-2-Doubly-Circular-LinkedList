#ifdef list_hpp

#define list_hpp

#include <iostream>

class List {
    private:
        struct Node{
            int data;
            int position;
            Node *next;
            Node *prev;
        };
        Node *head;
        Node *tail;
    public:
        List( ) {
            head = nullptr;
            tail = nullptr;
        }
        ~List( ) {
            while(head != nullptr){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        };

        void appendNode(int);
        void deleteNode(int);
        void insertNode(int, int);
        void displayList() const;
};
#endif