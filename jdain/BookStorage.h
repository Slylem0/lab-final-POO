#ifndef BOOKSTORAGE_H
#define BOOKSTORAGE_H

#include <vector>
#include <string>
#include "Book.h"

class BookStorage {
public:
    void saveBooks(const std::vector<Book>& books, const std::string& filename);
    std::vector<Book> loadBooks(const std::string& filename);
};

#endif