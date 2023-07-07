#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;
public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert node at the start
    void insertNode(int n) {
        Node* newNode = new Node();
        newNode->data = n;
        newNode->next = head;
        head = newNode;
    }

    // Count the number of nodes
    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Display the nodes
    void displayNodes() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // Insert nodes at the start
    myList.insertNode(13);
    myList.insertNode(11);
    myList.insertNode(9);
    myList.insertNode(7);
    myList.insertNode(5);
    myList.insertNode(3);
    myList.insertNode(1);

    // Display the original linked list
    cout << "Original linked list: ";
    myList.displayNodes();

    // Count the number of nodes
    int nodeCount = myList.countNodes();
    cout << "Number of nodes in the linked list: " << nodeCount << endl;

    return 0;
}
