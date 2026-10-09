#ifndef BOOK_H
#define BOOK_H

#include <fstream>
#include <string>
#include "json.hpp"

using nlohmann::json;

enum class Genre{
    Fiction,
    Technology,
    Documentary
};

inline std::string GenretoString(Genre genre) {
    switch(genre) {
    case Genre::Documentary: return "Documentary";
    case Genre::Fiction: return "Fiction";
    case Genre::Technology: return "Technology";
    default: return "Non-existed";
    }
}

inline Genre StringtoGenre(std::string string) {
    if (string == "Fiction") return Genre::Fiction;
    if (string == "Technology") return Genre::Technology;
    return Genre::Documentary;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<Genre> Genre_List) {
    for (size_t i = 0; i < Genre_List.size(); i++) {
        os << GenretoString(Genre_List.at(i));
        if (i < Genre_List.size() - 1) {
            os << ", ";
        }
    }
    return os;
}

NLOHMANN_JSON_SERIALIZE_ENUM(Genre, {
                                      {Genre::Fiction, "Fiction"},
                                      {Genre::Technology, "Technology"},
                                      {Genre::Documentary, "Documentary"},
                                      })

class Book {
private:
    int Released_Year;
    std::vector<Genre> Genre_List;
    std::string Name;
    std::string Author;
    int id;
public:
    Book() = default;
    Book(int Released_Year, std::string Name, std::string Author, std::vector<Genre> Genre_List) :
        Released_Year(Released_Year), Name(Name), Author(Author), Genre_List(Genre_List) {};

    Book(int Released_Year, std::string Name, std::string Author, std::vector<Genre> Genre_List, int id) :
        Released_Year(Released_Year), Name(Name), Author(Author), Genre_List(Genre_List), id(id) {};

    int getYear() const;
    std::string getName() const;
    std::string getAuthor() const;
    std::vector<Genre> getGenre() const;
    int getId() const;

    void setID(int i);
    void setGenre(Genre g);

    void display() const;
};



#endif // BOOK_H
