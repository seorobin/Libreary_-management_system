#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temp {
    string ID, Name, Author;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

void Temp::addBook() {
    file.open("books.txt", ios::app);
    if (!file) {
        cout << "File could not be opened!" << endl;
        return;
    }

    cout << "Enter Book ID: ";
    cin >> ID;
    cout << "Enter Book Name: ";
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, Name);
    cout << "Enter Author Name: ";
    getline(cin, Author);

    file << ID << "\n" << Name << "\n" << Author << "\n";
    file.close();
    cout << "Book added successfully!" << endl;
}

void Temp::showAll() {
    file.open("books.txt", ios::in);
    if (!file) {
        cout << "No books found!" << endl;
        return;
    }

    cout << "Books List:\n";
    while (getline(file, ID)) {
        getline(file, Name);
        getline(file, Author);
        cout << "ID: " << ID << ", Name: " << Name << ", Author: " << Author << endl;
    }

    file.close();
}

void Temp::extractBook() {
    string searchID;
    cout << "Enter Book ID to extract: ";
    cin >> searchID;

    file.open("books.txt", ios::in);
    if (!file) {
        cout << "No books found!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, ID)) {
        getline(file, Name);
        getline(file, Author);
        if (ID == searchID) {
            cout << "Book Found:\nID: " << ID << ", Name: " << Name << ", Author: " << Author << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }

    file.close();
}

int main() {
    Temp temp;
    char choice;

    do {
        cout << "................." << endl;
        cout << "1 - Show all books" << endl;
        cout << "2 - Extract Books" << endl;
        cout << "3 - Add Books" << endl;
        cout << "4 - Exit" << endl;
        cout << "................." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            temp.showAll();
            break;
        case '2':
            temp.extractBook();
            break;
        case '3':
            temp.addBook();
            break;
        case '4':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "INVALID CHOICE" << endl;
            break;
        }
    } while (choice != '4');

    return 0;
}
