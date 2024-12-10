#include "BookStorage.h"
#include <fstream>
#include <iostream>

void BookStorage::saveBooks(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    size_t size = books.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& book : books) {
        size_t titleSize = book.getTitle().size();
        outFile.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
        outFile.write(book.getTitle().c_str(), titleSize);

        size_t authorSize = book.getAuthor().size();
        outFile.write(reinterpret_cast<const char*>(&authorSize), sizeof(authorSize));
        outFile.write(book.getAuthor().c_str(), authorSize);

        int year = book.getPublicationYear();
        outFile.write(reinterpret_cast<const char*>(&year), sizeof(year));

        size_t categorySize = book.getCategory().size();
        outFile.write(reinterpret_cast<const char*>(&categorySize), sizeof(categorySize));
        outFile.write(book.getCategory().c_str(), categorySize);

        bool availability = book.getAvailability();
        outFile.write(reinterpret_cast<const char*>(&availability), sizeof(availability));
    }

    outFile.close();
}

std::vector<Book> BookStorage::loadBooks(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return books;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        size_t titleSize;
        inFile.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
        std::string title(titleSize, ' ');
        inFile.read(&title[0], titleSize);

        size_t authorSize;
        inFile.read(reinterpret_cast<char*>(&authorSize), sizeof(authorSize));
        std::string author(authorSize, ' ');
        inFile.read(&author[0], authorSize);

        int year;
        inFile.read(reinterpret_cast<char*>(&year), sizeof(year));

        size_t categorySize;
        inFile.read(reinterpret_cast<char*>(&categorySize), sizeof(categorySize));
        std::string category(categorySize, ' ');
        inFile.read(&category[0], categorySize);

        bool availability;
        inFile.read(reinterpret_cast<char*>(&availability), sizeof(availability));

        books.emplace_back(title, author, year, category, availability);
    }

    inFile.close();
    return books;
}