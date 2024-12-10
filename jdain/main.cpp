#include <iostream>
#include <fstream>
#include "Library.h"
#include "BookStorage.h"
using namespace std;

int main() {
    Library library;
    BookStorage storage;

    // Check if the file exists before loading
    ifstream inFile("books.bin", ios::binary);
    if (inFile) {
        vector<Book> loadedBooks = storage.loadBooks("books.bin");
        for (const auto& book : loadedBooks) {
            library.addBook(book, book.getCategory());
        }
    }
    inFile.close();

    // Add default categories
    library.addCategory("Fiction");
    library.addCategory("Science Fiction");
    library.addCategory("Horror");

    // Menu for user interaction
    int choice;
    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. View all books\n";
        cout << "2. Search books by title\n";
        cout << "3. Search books by author\n";
        cout << "4. Search books by year\n";
        cout << "5. Borrow a book\n";
        cout << "6. Return a book\n";
        cout << "7. Add a new book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // View all books
                cout << "\nBooks in the library:\n";
                for (const auto& category : library.getCategories()) {
                    cout << "Category: " << category.getName() << "\n";
                    for (const auto& book : category.getBooks()) {
                        cout << " - " << book.getTitle() << " by " << book.getAuthor()
                             << " (" << book.getPublicationYear() << ") ["
                             << (book.getAvailability() ? "Available" : "Borrowed") << "]\n";
                    }
                }
                break;
            }
            case 2: { // Search books by title
                cout << "\nEnter title fragment: ";
                string fragment;
                cin.ignore();
                getline(cin, fragment);
                auto results = library.searchByTitle(fragment);
                cout << "\nSearch results:\n";
                for (const auto& book : results) {
                    cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
                }
                break;
            }
            case 3: { // Search books by author
                cout << "\nEnter author fragment: ";
                string fragment;
                cin.ignore();
                getline(cin, fragment);
                auto results = library.searchByAuthor(fragment);
                cout << "\nSearch results:\n";
                for (const auto& book : results) {
                    cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
                }
                break;
            }
            case 4: { // Search books by year
                cout << "\nEnter publication year: ";
                int year;
                cin >> year;
                auto results = library.searchByYear(year);
                cout << "\nSearch results:\n";
                for (const auto& book : results) {
                    cout << " - " << book.getTitle() << " by " << book.getAuthor() << "\n";
                }
                break;
            }
            case 5: { // Borrow a book
                cout << "\nEnter the title of the book to borrow: ";
                string title;
                cin.ignore();
                getline(cin, title);
                if (library.borrowBook(title)) {
                    cout << "\nBook borrowed successfully.\n";
                } else {
                    cout << "\nBook not found or already borrowed.\n";
                }
                break;
            }
            case 6: { // Return a book
                cout << "\nEnter the title of the book to return: ";
                string title;
                cin.ignore();
                getline(cin, title);
                if (library.returnBook(title)) {
                    cout << "\nBook returned successfully.\n";
                } else {
                    cout << "\nBook not found or not borrowed.\n";
                }
                break;
            }
            case 7: { // Add a new book
                cout << "\nEnter the title of the book: ";
                string title;
                cin.ignore();
                getline(cin, title);

                cout << "Enter the author of the book: ";
                string author;
                getline(cin, author);

                cout << "Enter the publication year of the book: ";
                int year;
                cin >> year;
                cin.ignore();

                cout << "Enter the category of the book: ";
                string category;
                getline(cin, category);

                Book newBook(title, author, year, category, true); // Default availability to true
                library.addBook(newBook, category);
                cout << "\nBook added successfully.\n";
                break;
            }
            case 8:
                // Save books to a binary file before exiting
                    storage.saveBooks(library.getAllBooks(), "books.bin");
            cout << "\nExiting the system. Goodbye!\n";
            break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
