#include "Book.h"
#include <iostream>

using namespace std;

int Book::getYear() const {
    return Released_Year;
}

std::string Book::getAuthor() const {
    return Author;
}

std::string Book::getName() const {
    return Name;
}

std::vector<Genre> Book::getGenre() const {
    return Genre_List;
}

int Book::getId() const {
    return id;
}

void Book::setID(int i) {
    id = i;
}

void Book::setGenre(Genre g) {
    for (Genre genre: Genre_List) {
        if (genre == g) {
            return;
        }
    }
    Genre_List.push_back(g);
}

void Book::display() const {
    cout<< "Name: " << Name << "\n"
        << "Released Year: " << Released_Year << "\n"
         << "Genre: " << Genre_List << "\n"
         << "Author: " << Author << "\n"
         << "Id :" << id << "\n";
}

