
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>

using namespace std;

// Structure to store expense information
struct Expense {
    string category;
    string description;
    double amount;
};

// Collection to store all expenses
vector<Expense> expenses;

// Check whether a string contains non-space characters
bool isBlank(const string& text) {
    for (char ch : text) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            return false;
        }
    }
    return true;
}

// Convert text to lowercase
string toLowerCase(string text) {
    for (char& ch : text) {
        ch = static_cast<char>(
            tolower(static_cast<unsigned char>(ch))
        );
    }
    return text;
}

// Read and validate a positive expense amount
double getValidAmount() {
    string input;

    while (true) {
        cout << "Enter amount: Rs. ";
        getline(cin, input);

        stringstream ss(input);
        double amount;
        char extra;

        if ((ss >> amount) &&
            !(ss >> extra) &&
            isfinite(amount) &&
            amount > 0) {
            return amount;
        }

        cout << "Invalid amount! Please enter "
             << "a positive number.\n";
    }
}

// Add a new expense
void addExpense() {
    Expense expense;

    cout << "\n--- ADD EXPENSE ---\n";

    cout << "Enter category: ";
    getline(cin, expense.category);

    if (isBlank(expense.category)) {
        cout << "Category cannot be empty!\n";
        return;
    }

    cout << "Enter description: ";
    getline(cin, expense.description);

    if (isBlank(expense.description)) {
        cout << "Description cannot be empty!\n";
        return;
    }

    expense.amount = getValidAmount();

    expenses.push_back(expense);

    cout << "\nExpense added successfully!\n";
}

// Display all expenses
void listExpenses() {
    cout << "\n--- ALL EXPENSES ---\n";

    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left
         << setw(18) << "Category"
         << setw(25) << "Description"
         << right << setw(12) << "Amount\n";

    cout << string(55, '-') << "\n";

    for (const Expense& expense : expenses) {
        cout << left
             << setw(18) << expense.category
             << setw(25) << expense.description
             << right << fixed << setprecision(2)
             << setw(12) << expense.amount << "\n";
    }
}

// Calculate expenses for a particular category
void categoryTotal() {
    string category;

    cout << "\nEnter category: ";
    getline(cin, category);

    if (isBlank(category)) {
        cout << "Category cannot be empty!\n";
        return;
    }

    double total = 0;
    bool found = false;

    for (const Expense& expense : expenses) {
        if (toLowerCase(expense.category) ==
            toLowerCase(category)) {

            total += expense.amount;
            found = true;
        }
    }

    if (found) {
        cout << fixed << setprecision(2);
        cout << "Total for " << category
             << ": Rs. " << total << "\n";
    }
    else {
        cout << "No expenses found in this category.\n";
    }
}

// Calculate overall expenses
void overallTotal() {
    double total = 0;

    for (const Expense& expense : expenses) {
        total += expense.amount;
    }

    cout << fixed << setprecision(2);
    cout << "\nOverall Expense: Rs. "
         << total << "\n";
}

// Display the main menu
void displayMenu() {
    cout << "\n================================\n";
    cout << "         EXPENSE TRACKER\n";
    cout << "================================\n";
    cout << "1. Add Expense\n";
    cout << "2. List All Expenses\n";
    cout << "3. Category-wise Total\n";
    cout << "4. Overall Expense Total\n";
    cout << "5. Exit\n";
    cout << "================================\n";
}

// Main program
int main() {
    string choice;

    cout << "Welcome to Expense Tracker!\n";

    while (true) {
        displayMenu();

        cout << "Enter your choice: ";
        getline(cin, choice);

        if (choice == "1") {
            addExpense();
        }
        else if (choice == "2") {
            listExpenses();
        }
        else if (choice == "3") {
            categoryTotal();
        }
        else if (choice == "4") {
            overallTotal();
        }
        else if (choice == "5") {
            cout << "\nThank you for using "
                 << "Expense Tracker!\n";
            break;
        }
        else {
            cout << "\nInvalid choice! "
                 << "Please enter a number from 1 to 5.\n";
        }
    }

    return 0;
}
