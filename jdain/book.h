#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year, const std::string& category, bool availability);

    // Existing methods
    std::string getTitle() const;
    std::string getAuthor() const;
    int getPublicationYear() const;
    std::string getCategory() const;
    bool getAvailability() const;
    void borrow();
    void returnBook();

private:
    std::string title;
    std::string author;
    int year;
    std::string category;
    bool availability;
};

#endif