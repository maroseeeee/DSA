#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addAtStart(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Element " << value << " added at the start." << endl;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Element " << value << " added at the end." << endl;
    }

    void addAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position. Element not added." << endl;
            return;
        }

        if (position == 1) {
            addAtStart(value);
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position. Element not added." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Element " << value << " added at position " << position << "." << endl;
    }

    void deleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Element deleted from the start." << endl;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Element deleted from the end." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        delete curr;
        prev->next = nullptr;
        cout << "Element deleted from the end." << endl;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Element not deleted." << endl;
            return;
        }

        if (position == 1) {
            deleteAtStart();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;

        while (temp != nullptr && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position. Element not deleted." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Element deleted from position " << position << "." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, position;

    while (true) {
        cout << "1. ADD\n2. DELETE\n3. DISPLAY\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to add: ";
                cin >> value;
                cout << "1. Add at start\n2. Add at end\n3. Add at position\nEnter your choice: ";
                cin >> position;
                switch (position) {
                    case 1:
                        list.addAtStart(value);
                        break;
                    case 2:
                        list.addAtEnd(value);
                        break;
                    case 3:
                        cout << "Enter the position to add: ";
                        cin >> position;
                        list.addAtPosition(value, position);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;
            case 2:
                cout << "1. Delete at start\n2. Delete at end\n3. Delete at position\nEnter your choice: ";
                cin >> position;
                switch (position) {
                    case 1:
                        list.deleteAtStart();
                        break;
                    case 2:
                        list.deleteAtEnd();
                        break;
                    case 3:
                        cout << "Enter the position to delete: ";
                        cin >> position;
                        list.deleteAtPosition(position);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;
            case 3:
                list.display();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
