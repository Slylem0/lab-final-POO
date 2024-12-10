#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Category {
private:
    string name;
    vector<Book> books;

public:
    // Constructor
    Category(string n);

    // Getters
    string getName() const;


    //references to the books vector :D
    vector<Book>& getBooks();
    const vector<Book>& getBooks() const;


    void addBook(const Book& book);
};

#endif
