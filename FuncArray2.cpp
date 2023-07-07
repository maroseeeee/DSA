#include <iostream>
using namespace std;

const int ARRAY_SIZE = 15;
int arr[ARRAY_SIZE];
int length = 0;

void inputElements() {
    cout << "Enter 5 elements (separated by spaces): ";
    for (int i = 0; i < 5; i++) {
        if (cin >> arr[i]) {
            length++;
        } else {
            break;
        }
    }
    
    cout << "\nArray elements: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void addElement(int element) {
    if (length < ARRAY_SIZE) {
        arr[length] = element;
        length++;
        cout << "Element added successfully." << endl;
    } else {
        cout << "Array is full. Cannot add more elements." << endl;
    }
    
    cout << "\nArray elements: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteElement(int element) {
    bool found = false;
    for (int i = 0; i < length; i++) {
        if (arr[i] == element) {
            for (int j = i; j < length - 1; j++) {
                arr[j] = arr[j + 1];
            }
            length--;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Element deleted successfully." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    
    cout << "\nArray elements: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool searchElement(int element) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}



int main() {
    char choice;
    int element;

    while (true) {
        cout << "Menu:" << endl;
        cout << "a. Input elements" << endl;
        cout << "b. Add element" << endl;
        cout << "c. Delete element" << endl;
        cout << "d. Search element" << endl;
        cout << "e. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

       switch (choice) {
            case 'a':
                inputElements();
                break;
            case 'b':
                cout << "Enter element to add: ";
                cin >> element;
                addElement(element);
                break;
            case 'c':
                cout << "Enter element to delete: ";
                cin >> element;
                deleteElement(element);
                break;
            case 'd':
                cout << "Enter element to search: ";
                cin >> element;
                if (searchElement(element)) {
                    cout << "Element found in the array." << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            case 'e':
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
