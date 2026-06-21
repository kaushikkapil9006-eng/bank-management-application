#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore(); // used to discard the character

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount() const {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "\nInsufficient Balance!\n";
            return false;
        }

        balance -= amount;
        return true;
    }

    void saveToFile(ofstream &out) const {
        out << accountNumber << "\n";
        out << name << "\n";
        out << balance << "\n";
    }

    bool readFromFile(ifstream &in) {
        if (!(in >> accountNumber)) // Try to read a value from the input stream in into accountNumber.
            return false;// return false , if read operation fails

        in.ignore();
        getline(in, name);
        in >> balance;
        in.ignore();

        return true;
    }
};

void createAccount() {
    BankAccount acc;

    acc.createAccount();

    ofstream file("accounts.txt", ios::app);

    acc.saveToFile(file); // to save the details

    file.close();

    cout << "\nAccount Created Successfully!\n";
}

void checkBalance(int accNo) {//This function is used to search for an account by account number and display its details (including balance).
    ifstream file("accounts.txt");

    BankAccount acc;
    bool found = false;

    while (acc.readFromFile(file)) {
        if (acc.getAccountNumber() == accNo) {
            acc.displayAccount();
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nAccount Not Found!\n";
}

void depositMoney(int accNo, double amount) {
    ifstream file("accounts.txt");
    ofstream temp("temp.txt");
// This function deposits money into a specific account.
    BankAccount acc;
    bool found = false;

     (acc.readFromFile(file)) {
        if (acc.getAccountNumber() == accNo) { // if account number matches then 
            acc.dewhileposit(amount);git status
            found = true;
        }

        acc.saveToFile(temp);
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "\nDeposit Successful!\n";
    else
        cout << "\nAccount Not Found!\n";
}

void withdrawMoney(int accNo, double amount) {
    ifstream file("accounts.txt"); // input file stram 
    ofstream temp("temp.txt"); // output file stream
// above two are used to read and write the files
    BankAccount acc;
    bool found = false;

    while (acc.readFromFile(file)) {
        if (acc.getAccountNumber() == accNo) {
            found = true;
            acc.withdraw(amount);
        }

        acc.saveToFile(temp);
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "\nTransaction Completed!\n";
    else
        cout << "\nAccount Not Found!\n";
}

int main() {
    int choice;
    int accNo;
    double amount;

    do {
        cout << "\n\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount();
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            depositMoney(accNo, amount);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            withdrawMoney(accNo, amount);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;

            checkBalance(accNo);
            break;

        case 5:
            cout << "\nThank You for Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}