#include "Book.h"

Book::Book(const std::string& title, const std::string& author, int year, const std::string& category, bool availability)
    : title(title), author(author), year(year), category(category), availability(availability) {}

// Implement existing methods
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getPublicationYear() const { return year; }
std::string Book::getCategory() const { return category; }
bool Book::getAvailability() const { return availability; }
void Book::borrow() { availability = false; }
void Book::returnBook() { availability = true; }