#include "Category.h"

// Bob
Category::Category(string n) : name(n) {}


string Category::getName() const { return name; }


vector<Book>& Category::getBooks() {
    return books;
}


const vector<Book>& Category::getBooks() const {
    return books;
}


void Category::addBook(const Book& book) {
    books.push_back(book);
}

