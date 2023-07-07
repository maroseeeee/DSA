#include <iostream>
#include <queue>

using namespace std;

void displayMenu() {
    cout << "\n\t========== MENU: ==========" << endl;
    cout << "\t[A] Add Element" << endl;
    cout << "\t[B] Delete Element" << endl;
    cout << "\t[C] Search Element" << endl;
    cout << "\t[D] Display Element" << endl;
    cout << "\t[E] Identify the largest integer" << endl;
    cout << "\t[F] Exit" << endl;
}

int main() {
    queue<int> elements;
    char choice;

    do {
        displayMenu();
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A': 
            case 'a':
            {
                int element;
                cout << "\tEnter the integer to add: ";
                cin >> element;
                elements.push(element);
                cout << "\tElement added to the queue." << endl;
                break;
            }

            case 'B':
			case 'b': 
            {
                if (!elements.empty()) {
                    cout << "\tDeleted element: " << elements.front() << endl;
                    elements.pop();
                } else {
                    cout << "\tQueue is empty, cannot delete any element." << endl;
                }
                break;
            }

            case 'C': 
            case 'c':
            {
                int searchElement, index = 0;
                bool found = false;
                cout << "\tEnter the integer to search: ";
                cin >> searchElement;

                queue<int> tempQueue = elements;
                while (!tempQueue.empty()) {
                    if (tempQueue.front() == searchElement) {
                        found = true;
                        break;
                    }
                    tempQueue.pop();
                    index++;
                }

                if (found) {
                    cout << "\tElement found at index: " << index << endl;
                } else {
                    cout << "\tElement not found in the queue." << endl;
                }
                break;
            }

            case 'D': 
            case 'd':
            {
                if (!elements.empty()) {
                    queue<int> tempQueue = elements;
                    cout << "\tElements in the queue: ";
                    while (!tempQueue.empty()) {
                        cout << tempQueue.front() << " ";
                        tempQueue.pop();
                    }
                    cout << endl;
                } else {
                    cout << "\tQueue is empty." << endl;
                }
                break;
            }

            case 'E':
			case 'e': 
            {
                if (!elements.empty()) {
                    int largest = elements.front();
                    queue<int> tempQueue = elements;
                    while (!tempQueue.empty()) {
                        if (tempQueue.front() > largest) {
                            largest = tempQueue.front();
                        }
                        tempQueue.pop();
                    }
                    cout << "\tLargest integer in the queue: " << largest << endl;
                } else {
                    cout << "\tQueue is empty." << endl;
                }
                break;
            }

            case 'F':
        	case 'f':
                cout << "\tExiting program." << endl;
                break;

            default:
                cout << "\tInvalid choice. Please try again." << endl;
        }

    } while (choice != 'f');

    return 0;
}
