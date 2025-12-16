#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <vector>
using namespace std;

struct Expense {
    int id;
    string name;
    double amount;
};

void showMenu();
void addExpense(vector<Expense>& expenses);
double calculateTotal(const vector<Expense>& expenses);
void saveToFile(const vector<Expense>& expenses, const string& filename = "expenses.txt");
void loadFromFile(vector<Expense>& expenses, const string& filename = "expenses.txt");
void randomTip();

#endif
