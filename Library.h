#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) { if (!hasBook(b.getISBN())) books.push_back(b); }
    void addMember(const Member& m) {
        auto f = std::find_if(members.begin(), members.end(),
                              [&](const Member& x){ return x.getId() == m.getId(); });
        if (f == members.end()) members.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        return std::any_of(books.begin(), books.end(), [&](const Book& b){ return b.getISBN()==isbn; });
    }

    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& l : loans)
            if (l.getISBN()==isbn && !l.isReturned()) return false;
        return hasBook(isbn);
    }

    bool loanBook(const std::string& isbn, const std::string& m, const std::string& s, const std::string& d) {
        if (!isBookAvailable(isbn)) return false;
        loans.emplace_back(isbn, m, s, d);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& m) {
        for (auto& l : loans)
            if (l.getISBN()==isbn && l.getMember()==m && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        return false;
    }
};
