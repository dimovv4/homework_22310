#pragma once
#include <string>
#include <stdexcept>

class Member {
    std::string name, memberId;
    int yearJoined;
public:
    Member(): name("Unknown"), memberId("X"), yearJoined(1900) {}
    Member(const std::string& n, const std::string& id, int y): name(n), memberId(id), yearJoined(y) {
        if (id.empty()) throw std::invalid_argument("id");
    }
    const std::string& getId() const { return memberId; }
    std::string to_string() const { return name + " [" + memberId + "]"; }
};
