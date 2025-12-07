#include <iostream>
#include "Library.h"

int main() {
    Library lib;

    Author a{"Ivan Vazov", 1850};

    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);

    lib.addMember(Member{"Petar Petrov", "M001", 2023});

    std::cout << b1.to_string() << "\n";
    std::cout << b2.to_string() << "\n";

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17")) {
        std::cout << "Loan created.\n";
    }

    std::cout << "Available ISBN-001? " 
              << std::boolalpha 
              << lib.isBookAvailable("ISBN-001") 
              << "\n";

    lib.returnBook("ISBN-001", "M001");

    std::cout << "Available ISBN-001? " 
              << std::boolalpha 
              << lib.isBookAvailable("ISBN-001") 
              << "\n";

    for (const auto& book : std::vector<Book>{b1, b2}) {
        if (book.getAuthor().getName().find("Vazov") != std::string::npos) {
            std::cout << book.to_string() << "\n";
        }
    }

    std::cout << "Total books: " << Book::getTotalBooks() << "\n";

    return 0;
}
