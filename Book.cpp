#include "Book.h"
#include <stdexcept>

int Book::totalBooks = 0;

Book::Book() : title("Untitled"), author(), year(1900), price(0), isbn("") { ++totalBooks; }

Book::Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
    : title(t), author(a), year(y), price(p), isbn(i)
{
    if (y < 1450 || y > 2025) throw std::out_of_range("year");
    if (p < 0) throw std::invalid_argument("price");
    ++totalBooks;
}

Book::Book(const Book& o) : title(o.title), author(o.author), year(o.year), price(o.price), isbn(o.isbn) {
    ++totalBooks;
}

Book::Book(Book&& o) noexcept : title(std::move(o.title)), author(o.author),
    year(o.year), price(o.price), isbn(std::move(o.isbn)) { ++totalBooks; }

Book& Book::operator=(const Book& o) {
    if (this != &o) { title=o.title; author=o.author; year=o.year; price=o.price; isbn=o.isbn; }
    return *this;
}

Book& Book::operator=(Book&& o) noexcept {
    if (this != &o) { title=std::move(o.title); author=o.author; year=o.year; price=o.price; isbn=std::move(o.isbn); }
    return *this;
}

Book::~Book() { --totalBooks; }

std::string Book::to_string() const {
    return title + " by " + author.to_string() + " (" + std::to_string(year) + ")";
}
