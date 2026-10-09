#include <iostream>

using namespace std;

/// ID, Total JSON, Search

#include "Library.h"
#include "Book.h"
#include "BookManager.h"
#include "RepairJson.h"

#include <iostream>
#include <fstream>

int main()
{
    std::vector<Genre> genrelist = {Genre::Fiction, Genre::Technology};
    {
        Library l;
        Book* newbook = new Book(1990, "BookName", "Long", genrelist);
        ///l.addBook(1990, "BookName", "Long", genrelist);
        ///l.addCustomer("Long");
        l.addTransaction(1,1);
    }

    std::ifstream read("Books.json");
    json j;
    read >> j;


    cout << j.dump(4) << endl;
    return 0;
}
