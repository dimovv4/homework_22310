#pragma once
#include <string>
#include <stdexcept>

class Loan {
    std::string isbn, memberId, start, due;
    bool returned;
public:
    Loan(const std::string& i, const std::string& m, const std::string& s, const std::string& d)
        : isbn(i), memberId(m), start(s), due(d), returned(false)
    {
        if (d < s) throw std::invalid_argument("date");
    }

    bool isReturned() const { return returned; }
    void markReturned() { returned = true; }
    const std::string& getISBN() const { return isbn; }
    const std::string& getMember() const { return memberId; }
};
