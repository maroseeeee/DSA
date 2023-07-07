#include <iostream>

using namespace std;

int main() {
    int count = 1;
    int number;
    int largest, smallest, sum = 0;
	char choice;
    bool exitProgram = false;

    cout << "Enter 10 numbers:\n";

    
    while (count <= 10) {
    	cout << "Number " << count << ": ";
        cin >> number;

        if (count == 1) {
            largest = smallest = number;
        } else {
            if (number > largest) {
                largest = number;
            }
            if (number < smallest) {
                smallest = number;
            }
        }

        sum += number;
        count++;

        if (number == -1) {
            exitProgram = true;
            break;
        }
        
        cout << "A. Average\n"
                    "B. Largest\n"
                    "C. Smallest\n"
                    "D. Exit\n"
                    "Choose a letter: ";
    	cin >> choice;
    }

    if (!exitProgram) {
        double average = static_cast<double>(sum) / 10;
        
         switch (choice) {
        case 'A' :
            cout << "Average: " << average << endl;
            break;
        case 'B' :
            cout << "Largest: " << largest << endl;
            break;
        case 'C' :
            cout << "Smallest: " << smallest << endl;
            break;
        case 'D' :
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

        cout << "\nResults:\n";
        cout << "Average: " << average << endl;
        cout << "Largest: " << largest << endl;
        cout << "Smallest: " << smallest << endl;
    }

    cout << "Exiting the program.\n";

    return 0;
}