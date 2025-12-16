#include "Expense.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

static int nextId = 1;   // static variable requirement

void showMenu() {
    cout << "\n===== Student Expense Tracker =====\n";
    cout << "1. Add Expense\n";
    cout << "2. View Total Expenses\n";
    cout << "3. Save Expenses to File\n";
    cout << "4. Load Expenses from File\n";
    cout << "5. Random Budget Tip\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void addExpense(vector<Expense>& expenses) {
    Expense e;
    e.id = nextId++;

    cout << "Enter expense name: ";
    cin.ignore();
    getline(cin, e.name);

    cout << "Enter amount: ";
    while (!(cin >> e.amount) || e.amount <= 0) {
        cout << "Invalid amount. Try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    expenses.push_back(e);
    cout << "Expense added!\n";
}

double calculateTotal(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const Expense& e : expenses) {   // range-based for loop
        total += e.amount;
    }
    return total;
}

void saveToFile(const vector<Expense>& expenses, const string& filename) {
    ofstream outFile(filename);
    for (const Expense& e : expenses) {
        outFile << e.id << "," << e.name << "," << e.amount << endl;
    }
    outFile.close();
    cout << "Expenses saved to file.\n";
}

void loadFromFile(vector<Expense>& expenses, const string& filename) {
    ifstream inFile(filename);
    expenses.clear();

    if (!inFile) {
        cout << "No file found.\n";
        return;
    }

    Expense e;
    char comma;
    while (inFile >> e.id >> comma) {
        getline(inFile, e.name, ',');
        inFile >> e.amount;
        expenses.push_back(e);
    }

    inFile.close();
    cout << "Expenses loaded.\n";
}

void randomTip() {
    const int TIP_COUNT = 3;
    srand(time(NULL));

    int choice = rand() % TIP_COUNT;

    if (choice == 0)
        cout << "Tip: Track small expenses — they add up!\n";
    else if (choice == 1)
        cout << "Tip: Set a weekly spending limit.\n";
    else
        cout << "Tip: Save at least 10% of your income.\n";
}
