#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    int quantity;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayBook() {
        cout << "\nBook ID: " << bookId;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nQuantity: " << quantity << endl;
    }

    void saveToFile(ofstream &out) { //  & means pass by reference.
        out << bookId << endl;
        out << title << endl;
        out << author << endl;
        out << quantity << endl;
    }

    bool readFromFile(ifstream &in) {
        if (!(in >> bookId)) // // tries to read an integer from a file and store in bookID
            return false;

        in.ignore();

        getline(in, title);
        getline(in, author);

        in >> quantity; // how much books 
        in.ignore();

        return true;
    }

    int getBookId() {
        return bookId;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getQuantity() {
        return quantity;
    }

    void issueBook() {
        if (quantity > 0)
            quantity--;
    }

    void returnBook() {
        quantity++;
    }
};

void addBook() {
    Book book;

    book.addBook();

    ofstream file("books.txt", ios::app);

    book.saveToFile(file);

    file.close();

    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {
    ifstream file("books.txt");

    Book book;

    cout << "\n===== BOOK LIST =====\n";

    while (book.readFromFile(file)) {
        book.displayBook();
        cout << "-------------------\n";
    }

    file.close();
}

void searchByTitle(string searchTitle) {
    ifstream file("books.txt");

    Book book;
    bool found = false;

    while (book.readFromFile(file)) {
        if (book.getTitle() == searchTitle) {
            book.displayBook();
            found = true;
        }
    }

    if (!found)
        cout << "\nBook Not Found!\n";

    file.close();
}

void searchByAuthor(string searchAuthor) {
    ifstream file("books.txt");

    Book book;
    bool found = false;

    while (book.readFromFile(file)) {
        if (book.getAuthor() == searchAuthor) {
            book.displayBook();
            found = true;
        }
    }

    if (!found)
        cout << "\nBook Not Found!\n";

    file.close();
}

void issueBook(int id) {
    ifstream file("books.txt");
    ofstream temp("temp.txt");

    Book book;
    bool found = false;

    while (book.readFromFile(file)) {
        if (book.getBookId() == id) {
            if (book.getQuantity() > 0) {
                book.issueBook();
                cout << "\nBook Issued Successfully!\n";
            } else {
                cout << "\nBook Out of Stock!\n";
            }
            found = true;
        }

        book.saveToFile(temp);
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found)
        cout << "\nBook Not Found!\n";
}

void returnBook(int id) {
    ifstream file("books.txt");
    ofstream temp("temp.txt");

    Book book;
    bool found = false;

    while (book.readFromFile(file)) {
        if (book.getBookId() == id) {
            book.returnBook();
            found = true;
        }

        book.saveToFile(temp);
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "\nBook Returned Successfully!\n";
    else
        cout << "\nBook Not Found!\n";
}

int main() {
    int choice;
    int id;
    string text;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search By Title\n";
        cout << "4. Search By Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            cout << "Enter Title: ";
            getline(cin, text);
            searchByTitle(text);
            break;

        case 4:
            cout << "Enter Author: ";
            getline(cin, text);
            searchByAuthor(text);
            break;

        case 5:
            cout << "Enter Book ID: ";
            cin >> id;
            issueBook(id);
            break;

        case 6:
            cout << "Enter Book ID: ";
            cin >> id;
            returnBook(id);
            break;

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}