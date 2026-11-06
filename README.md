# Reliable Command-Line Utility – Expense Tracker

## Project Overview

The Expense Tracker is a beginner-friendly command-line application developed using C++. It allows users to record and manage daily expenses through a simple menu-driven interface.

Users can add expenses, view all recorded expenses, calculate category-wise totals, and calculate their overall spending.

The application also includes input validation to handle incorrect entries and prevent unexpected program termination.

## Features

- Add new expenses with category, description, and amount.
- Display all recorded expenses in a readable format.
- Calculate total expenses for a specific category.
- Calculate the overall expense total.
- Validate positive numeric amounts.
- Handle invalid menu choices.
- Perform case-insensitive category searches.
- Display monetary values up to two decimal places.

## Technologies Used

- Programming Language: C++
- Compiler: GCC / G++
- Code Editor: Visual Studio Code
- Standard: C++17

## Project Structure

```text
cpp-expense-tracker/
│
├── expense_tracker.cpp
├── README.md
├── menu.png
├── expenses.png
└── validation.png
```

## How to Compile

Make sure G++ is installed on your computer.

Open the terminal in the project folder and execute:

```bash
g++ -std=c++17 -Wall -Wextra expense_tracker.cpp -o expense_tracker.exe
```

## How to Run

On Windows, execute:

```powershell
.\expense_tracker.exe
```

## Application Menu

The application provides five options:

1. Add Expense
2. List All Expenses
3. Category-wise Total
4. Overall Expense Total
5. Exit

## Input Validation

The program handles:

- Invalid menu selections.
- Negative expense amounts.
- Alphabetic or non-numeric amount inputs.
- Empty categories.
- Empty descriptions.
- Categories that do not exist.

The program asks the user to enter valid information instead of crashing.

## Testing

The following test cases were performed:

- Successfully adding expenses.
- Displaying all expense records.
- Calculating category-wise totals.
- Calculating the overall total.
- Testing invalid menu inputs.
- Testing negative and alphabetic amounts.
- Testing empty category inputs.
- Searching for non-existing categories.

## Screenshots

Sample execution screenshots are available in the `screenshots` folder.

1. Program menu – `screenshots/menu.png`
2. Expense records – `screenshots/expenses.png`
3. Input validation – `screenshots/validation.png`

## Limitations

Expenses are stored in memory using a C++ vector. Data is not permanently saved and will be cleared when the application closes.

## Learning Outcomes

Through this project, I practiced:

- C++ structures and variables.
- Vectors and collections.
- Functions and modular programming.
- Loops and conditional statements.
- String handling.
- Input validation and error handling.
- Basic calculations and formatted output.
