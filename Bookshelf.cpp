#include "Bookshelf.h"
#include "Genreshelf.h"

std::vector<Genreshelf*>& Bookshelf::getList() {
    return List_Genreshelf;
}

void Bookshelf::addBook(Book* b) {
    for (Genreshelf* gs: List_Genreshelf) {
        gs->addBook(b);
    }
}