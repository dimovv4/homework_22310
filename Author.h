#pragma once
#include <string>
#include <stdexcept>

class Author {
    std::string name;
    int birthYear;
public:
    Author(): name("Unknown"), birthYear(1900) {}
    Author(const std::string& n, int y): name(n), birthYear(y) {
        if (y < 1850 || y > 2025) throw std::out_of_range("year");
    }

    const std::string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }
    void setBirthYear(int y) {
        if (y < 1850 || y > 2025) throw std::out_of_range("year");  
        birthYear = y;
    }

    std::string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};
