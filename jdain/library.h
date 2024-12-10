#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Category.h"

class Library {
public:
    void addCategory(const std::string& name);
    void addBook(const Book& book, const std::string& category);
    std::vector<Category> getCategories() const;
    std::vector<Book> searchByTitle(const std::string& title) const;
    std::vector<Book> searchByAuthor(const std::string& author) const;
    std::vector<Book> searchByYear(int year) const;
    bool borrowBook(const std::string& title);
    bool returnBook(const std::string& title);
    std::vector<Book> getAllBooks() const;

private:
    std::vector<Category> categories;
};

#endif