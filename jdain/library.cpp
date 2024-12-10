#include "Library.h"

void Library::addCategory(const std::string& name) {
    categories.emplace_back(name);
}

void Library::addBook(const Book& book, const std::string& category) {
    for (auto& cat : categories) {
        if (cat.getName() == category) {
            cat.addBook(book);
            return;
        }
    }
    // If category not found, create a new one and add the book
    Category newCategory(category);
    newCategory.addBook(book);
    categories.push_back(newCategory);
}

std::vector<Category> Library::getCategories() const {
    return categories;
}

std::vector<Book> Library::searchByTitle(const std::string& title) const {
    std::vector<Book> results;
    for (const auto& category : categories) {
        for (const auto& book : category.getBooks()) {
            if (book.getTitle().find(title) != std::string::npos) {
                results.push_back(book);
            }
        }
    }
    return results;
}

std::vector<Book> Library::searchByAuthor(const std::string& author) const {
    std::vector<Book> results;
    for (const auto& category : categories) {
        for (const auto& book : category.getBooks()) {
            if (book.getAuthor().find(author) != std::string::npos) {
                results.push_back(book);
            }
        }
    }
    return results;
}

std::vector<Book> Library::searchByYear(int year) const {
    std::vector<Book> results;
    for (const auto& category : categories) {
        for (const auto& book : category.getBooks()) {
            if (book.getPublicationYear() == year) {
                results.push_back(book);
            }
        }
    }
    return results;
}

bool Library::borrowBook(const std::string& title) {
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getTitle() == title && book.getAvailability()) {
                book.borrow();
                return true;
            }
        }
    }
    return false;
}

bool Library::returnBook(const std::string& title) {
    for (auto& category : categories) {
        for (auto& book : category.getBooks()) {
            if (book.getTitle() == title && !book.getAvailability()) {
                book.returnBook();
                return true;
            }
        }
    }
    return false;
}

std::vector<Book> Library::getAllBooks() const {
    std::vector<Book> allBooks;
    for (const auto& category : categories) {
        for (const auto& book : category.getBooks()) {
            allBooks.push_back(book);
        }
    }
    return allBooks;
}