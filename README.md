# Expense Tracker in C++ (Singly Linked List)

A lightweight, console-based Expense Tracker built using C++ and singly linked lists. This program allows users to track, update, and manage daily expenses, along with generating a summary of expenses by category on a specific date.

## Features

- Add expense entries (date, amount, category, description)
- View all expenses in a structured table format
- Edit existing expenses based on date and category
- Delete expenses based on date and category
- Generate a summary report for a given date

## C++ Topics Covered

This project demonstrates the following C++ concepts:

- Structs for defining custom node types
- Singly linked list data structure
- Dynamic memory allocation using `new` and `delete`
- Pointer manipulation to traverse and modify linked nodes
- Class design and object-oriented programming
- Input/output handling (`cin`, `cout`)
- Control flow with `if`, `while`, and `break`

## File Structure

```
ExpenseTracker/
├── main.cpp        // Contains the Expense struct, ExpenseTracker class, and main function
└── README.md       // Project documentation
```

## Sample Usage

### Code:
```cpp
ET.add_expense("2025-10-01", 12.99, "Groceries", "Fruits and Vegetables");
ET.add_expense("2025-10-05", 45.00, "Utilities", "Electric Bill");
ET.view_expenses();
ET.edit_expense("2025-10-01", 15.00, "Groceries");
ET.delete_expense("2025-10-05", "Utilities");
ET.generate_summary("2025-10-01");
```

### Output:
```
| Date        | Amount   | Category   | Description          |
|-------------|----------|------------|----------------------|
| 2025-10-01  | $15.0    | Groceries  | Fruits and Vegetables |

| Category   | Total Spent |
|------------|--------------|
| Groceries  | $15.0        |
| Total      | $15.0        |
```

## How to Run

1. Clone or download the repository
2. Compile the program:
   ```
   g++ -o expense_tracker main.cpp
   ```
3. Run it:
   ```
   ./expense_tracker
   ```

## Future Enhancements

- Save and load expense data from a file
- Group and sort expenses by category or date
- Add date format validation
- Monthly and weekly spending summaries

## Author

Raid Mowla  
Email: dearraid@gmail.com  
LinkedIn: https://www.linkedin.com/in/raid-mowla/  
GitHub: [Your GitHub Username]

## License

This project is open source and free to use under the MIT License.
