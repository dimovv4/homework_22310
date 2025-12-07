#pragma once
#include "Author.h"
#include <string>

class Book {
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;
public:
    static int getTotalBooks() { return totalBooks; }

    Book();
    Book(const std::string&, const Author&, int, double, const std::string&);
    Book(const Book&);
    Book(Book&&) noexcept;
    Book& operator=(const Book&);
    Book& operator=(Book&&) noexcept;
    ~Book();

    const std::string& getISBN() const { return isbn; }
    const Author& getAuthor() const { return author; }

    std::string to_string() const;
};
