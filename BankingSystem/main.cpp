#include <iostream>
#include <cassert> // For assertions
using namespace std;

int main() {
    double balance = 0.0;
    int choice;
    double amount;

    while (true) {
        // Display the menu
        cout << "\n========== Banking System ==========" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Switch handles the menu logic
        switch (choice) {
            case 1:  // Deposit
                cout << "Enter amount to deposit: $";
                cin >> amount;

                // Selection structure with logical operator
                if (amount > 0 && amount < 100000) {
                    balance += amount;

                    // Assertion to ensure balance is never negative after deposit
                    assert(balance >= 0);
                    cout << "Successfully deposited $" << amount << "." << endl;
                    cout << "Updated Balance: $" << balance << endl;
                } else {
                    cout << "Invalid amount. Please enter a positive number less than 100000." << endl;
                }
                break;

            case 2:  // Withdraw
                cout << "Enter amount to withdraw: $";
                cin >> amount;

                // Use selection + logical operators
                if (amount <= 0 || amount > balance) {
                    cout << "Invalid withdrawal. Must be > 0 and <= current balance." << endl;
                } else {
                    balance -= amount;

                    // Assertion to prevent negative balance
                    assert(balance >= 0);
                    cout << "Successfully withdrew $" << amount << "." << endl;
                    cout << "Updated Balance: $" << balance << endl;
                }
                break;

            case 3:  // Check Balance
                cout << "Current Balance: $" << balance << endl;
                break;

            case 4:  // Exit
                cout << "Exiting program. Thank you for using the Banking System!" << endl;
                return 0;

            default:
                cout << "Invalid option. Please enter a number from 1 to 4." << endl;
                break;
        }
    }

    return 0;
}