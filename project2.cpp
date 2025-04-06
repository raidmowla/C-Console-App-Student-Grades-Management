#include <iostream>
#include <string>
using namespace std;
struct Expense {
    string date;
    double amount;
    string category;
    string description;
    Expense* next;
};
class ExpenseTracker {
private:
    Expense* head;

public:
    ExpenseTracker() { head = nullptr; }
    void add_expense(string date, double amount,string category,string description) {
        Expense* exp = new Expense();
        exp->date = date;
        exp->amount =  amount;
        exp->category= category;
        exp->description = description;
        exp->next= nullptr;
        if (!head) {
            head = exp;
            return;
        }
        Expense* temp= head;
        while (temp->next)
            temp = temp->next;
        temp->next= exp;
    }
    void view_expenses() {
        // handles empty list cases by exiting early
        if (!head) {
            cout << "No tracked expenses" << endl;
            return;
        }
        // the column has been set with approximated spacings
        Expense* temp = head;
        cout << "| Date |       Amount |     Category |    Description |\n";
        cout << "|------------|--------|------------|--------|\n";
        while (temp) {
            cout << "| " << temp->date << " | $" << temp->amount << " | " << temp->category << " | " << temp->description <<
                " |\n";
            temp = temp->next;
        }
    }
    void edit_expense(string date, double amount, string category) {
        Expense* temp = head;
        bool found = false; //found has been placed to track if there's any expense,
        //if 'found = true'; a break cause
        while (temp) {
            if (temp->date == date && temp->category == category) {
                temp->amount = amount;
                found = true; // while breaks as soon as 'found' flips
                break;
            }
            temp = temp->next; //and now the current node is the next node
        }
        if (!found)
            cout << "no expense found";
    }

    void delete_expense(string date, string category) {
        Expense* temp = head;
        Expense* prev = nullptr;
        //'prev' is mainly being used to adjust the
        //next pointers when removing a node in this case
        bool found = false;
        while (temp) {
            if (temp->date == date && temp->category == category) {
                if (prev)
                    prev->next = temp->next; //if prev is not nullptr; the middle node, the user given node(temp) gets skipped
                else
                    head = temp->next; // in case when prev->nullptr
                delete temp; //deleted expense is cleaned up from the memory
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (!found)
            cout << "No matched expense found.";
    }
    void generate_summary(string date) {
        Expense* temp = head;
        double sum = 0;
        cout << "| Category | Total Spent |\n";
        cout << "|-----------|--------------|\n";
        while (temp) {
            if (temp->date == date) {
                cout <<"| "<< temp->category << " | $" << temp->amount << " |\n";
                sum += temp->amount;
            }
            temp = temp ->next;
        }
        cout<<"| **Total **| **$" <<sum<< "** |\n";
    }
};

int main() {
    ExpenseTracker ET;
    ET.add_expense("2025-10-01", 12.99, "Groceries", "Fruits and Vegetables");
    ET.add_expense("2025-10-05", 45.00, "Utilities", "Electric Bill");
    ET.view_expenses();
    ET.edit_expense("2025-10-01", 15.00, "Groceries");
    ET.delete_expense("2025-10-05", "Utilities");
    ET.generate_summary("2025-10-01");
    return 0;
}
