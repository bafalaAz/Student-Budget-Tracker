The Student Expense Tracker is a console-based C++ application that allows users to record and manage personal expenses. Users can add expenses, calculate the total amount spent, save expense data to a file, load previously saved data, and receive random budgeting tips. The program uses modular programming with multiple files and demonstrates file input/output, data structures, and user interaction.
How to Compile and Run the Program?
Compile
Open a terminal in the project folder and run:

g++ main.cpp Expense.cpp -o tracker

Run (Mac/Linux)
./tracker

Run (Windows)
tracker.exe

      Example Menu Output
      
===== Student Expense Tracker =====
1. Add Expense
2. View Total Expenses
3. Save Expenses to File
4. Load Expenses from File
5. Random Budget Tip
6. Exit
Choose an option:
Example Input
1
Food
12.50$

Example Output
Expense added!

View Total Expenses
Total Expenses: $12.50

Save to File
Expenses saved to file.

Random Tip Output
Tip: Track small expenses — they add up!
