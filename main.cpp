#include <iostream>
#include <vector>
#include "Expense.h"

using namespace std;

int main() {
    vector<Expense> expenses;
    int choice = 0;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addExpense(expenses);
            break;

        case 2: {
            double total = calculateTotal(expenses);
            cout << "Total Expenses: $" << total << endl;
            break;
        }

        case 3:
            saveToFile(expenses);
            break;

        case 4:
            loadFromFile(expenses);
            break;

        case 5:
            randomTip();
            break;

        case 6:
            running = false;
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
