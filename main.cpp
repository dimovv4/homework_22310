#include <iostream>
#include "Library.h"

int main() {
    Library lib;
    Author a{"Ivan Vazov",1850};
    Book b1{"Pod igoto",a,1894,25.5,"ISBN-001"};
    Book b2{"Nema zemya",a,1900,18.9,"ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(Member{"Petar Petrov","M001",2023});

    lib.loanBook("ISBN-001","M001","2025-11-03","2025-11-17");
    lib.returnBook("ISBN-001","M001");

    std::cout << b1.to_string() << "\n";
}
