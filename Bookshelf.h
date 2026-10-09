#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <vector>

#include "Book.h"

class Genreshelf;

class Bookshelf{
private:
    int NumberofBooks;
    std::vector<Genreshelf*> List_Genreshelf;
public:
    Bookshelf() = default;
    std::vector<Genreshelf*>& getList();
    void addBook(Book* b);
};

#endif // BOOKSHELF_H
