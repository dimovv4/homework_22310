# Library System
## Описание

Проектът **„Библиотека“** представлява малка C++ система за управление на книги, автори, читатели и заеми.
Системата демонстрира основни обектно-ориентирани концепции в C++:

- Конструктори и деструктори
- Капсулация и достъп чрез getters и setters
- Const-коректност и валидация на данни
- Статични членове и методи
- Добри ООП практики (Rule of 5, списъци за инициализация, =default, =delete)

---

## Структура на проекта

```
library/
├── Author.h
├── Book.h
├── Book.cpp
├── Member.h
├── Member.cpp
├── Loan.h
├── Library.h
├── main.cpp
└── output/
```

---

## Компилация и изпълнение

Отворете терминал в директорията library/ и изпълнете:

```
g++ -std=c++17 -Wall -Wextra -O2 main.cpp Book.cpp -o output/main.exe
```

След това стартирайте програмата:
```
./output/main.exe
```
## Примерен изход
```
Pod igoto by Ivan Vazov (1850) (1894)
Nema zemya by Ivan Vazov (1850) (1900)
Loan created.
Available ISBN-001? false
Available ISBN-001? true
Pod igoto by Ivan Vazov (1850) (1894)
Nema zemya by Ivan Vazov (1850) (1900)
Total books: 2
```

---

## Класове
# Kлас Author

Представя автор с име и година на раждане.

**Членове:**

- `std::string name` — име на автора

- `int birthYear` — година на раждане

**Методи:**

- `Author()` — конструктор по подразбиране

- `Author(const std::string&, int)` — параметризиран конструктор

- `setBirthYear(int)` — задава година с валидация

- `getName(), getBirthYear()` — достъп до членове

- `to_string()` — текстово представяне

---

### Клас Book

Представя книга с основни характеристики.

**Членове:**

- `std::string title` — заглавие

- `Author author` — автор

- `int year` — година на издаване

- `double price` — цена

- `std::string isbn` — уникален идентификатор

- `static int totalBooks` — брояч на всички създадени книги

## Методи:

- Конструктори: по подразбиране, параметризиран, копиращ, преместващ

- Оператори: копиращ, преместващ, деструктор (Rule of 5)

- Getters и setters с валидиране

- `to_string()` — текстово представяне

- `static int getTotalBooks()` — връща броя на създадените книги

## Клас Member

Представя читател на библиотеката.

# Членове:

- `std::string name` — име

- `std::string memberId` — идентификатор

- `int yearJoined` — година на присъединяване

# Методи:

Конструктори: по подразбиране и параметризиран

- `to_string()` — текстово представяне

# Клас Loan

Представя заем на книга.

# Членове:

- `std::string isbn` — ISBN на книгата

- `std::string memberId` — идентификатор на читателя

- `std::string startDate` — дата на започване

- `std::string dueDate` — дата на край

- `bool returned` — флаг за върната книга

# Методи:

- `markReturned()` — маркира заета книга като върната

- `isOverdue(const std::string&)` — проверка за изтекъл срок

- `to_string()` — текстово представяне

# Клас Library

Управлява книгите, читателите и заемите.

Членове:

- `std::vector<Book> books`

- `std::vector<Member> members`

- `std::vector<Loan> loans`

# Методи:

- `addBook(const Book&)` — добавя книга

- `addMember(const Member&)` — добавя читател

- `hasBook(const std::string&)` — проверка за книга

- `isBookAvailable(const std::string&)` — проверка за наличност

- `loanBook(...)` — създава заем

- `returnBook(...)` — връща книга

- `findByAuthor(...)` — намира книги по автор

- `to_string()` — обобщена информация за библиотеката

## Екранна снимка 

<img width="1076" height="72" alt="image" src="https://github.com/user-attachments/assets/6c71609c-271b-44bf-9a11-7f968fa6e950" />
