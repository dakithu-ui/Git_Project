#include "Library.h"
#include "BookManager.h"
#include "VipCustomer.h"

#include <fstream>
#include <iostream>

using namespace std;


std::vector<Book*> Library::getList_Book() const {
    return List_Book;
}

void Library::addBook(int Released_Year, std::string Name, std::string Author, std::vector<Genre> Genre_List) {
    List_Book.push_back(new Book(Released_Year, Name, Author, Genre_List, Total_Book));
    Total_Book += 1;
}

std::vector<Customer*> Library::getList_Customer() const {
    return List_Customer;
}

void Library::addCustomer(std::string Name) {
    List_Customer.push_back(new Customer(Name, Total_Customer));
    Total_Customer += 1;
}
/// Kiem tra khach hang va them vao Transaction History
std::vector<Transaction*> Library::getList_Transaction() const {
    return List_Transaction;
}

void Library::addTransaction(int b_id, int c_id) {
    if (getBookbyId(b_id) == nullptr) {
        cout << "Book does not exist" << endl;
        return;
    }
    Customer* temp_customer = getCustomerbyId(c_id);
    if (temp_customer == nullptr) {
        cout << "Customer does not exist" << endl;
         return;
    }
    int t_id = Total_Transaction;
    temp_customer->addTransaction(t_id);
    List_Transaction.push_back(new Transaction(t_id, b_id, c_id));
    Total_Transaction += 1;
}

void Library::deserialize() {

    json json_temp;
    std::ifstream json_stream("Books.json");

    if (!json_stream.is_open() || json_stream.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Initiated First Book" << std::endl;
        return;
    }

    json_stream >> json_temp;
    if (!json_temp.contains("Books")) {
        json_temp["Books"] = json::array();
    }

    if (!json_temp.contains("Customers")) {
        json_temp["Customers"] = json::array();
    }

    if (!json_temp.contains("Transactions")) {
        json_temp["Transactions"] = json::array();
    }
    if (!json_temp.contains("Data")) {
        json_temp["Data"] = {
            {"Total_Book", 0},
            {"Total_Customer", 0},
            {"Total_Transaction", 0}
        };
    }


    for (const auto& item : json_temp["Books"]) {
        List_Book.push_back(new Book(item.get<Book>()));
    }

    for (const auto& item : json_temp.at("Customers")) {
        if (item.at("IsVip")) {
            List_Customer.push_back(new VipCustomer(item.get<VipCustomer>()));
        } else {
            List_Customer.push_back(new Customer(item.get<Customer>()));
        }
    }

    for (const auto& item: json_temp["Transactions"]) {
        List_Transaction.push_back(new Transaction(item.get<Transaction>()));
    }


    json Total = json_temp.at("Data").get<json>();
    Total_Book = Total.at("Total_Book").get<int>();
    Total_Customer = Total.at("Total_Customer").get<int>();
    Total_Transaction = Total.at("Total_Transaction").get<int>();
}

void Library::serialize() {
    json Library_json;
    Library_json["Data"]["Total_Book"] = Total_Book;
    Library_json["Data"]["Total_Customer"] = Total_Customer;
    Library_json["Data"]["Total_Transaction"] = Total_Transaction;

    Library_json["Books"] = json::array();
    Library_json["Customers"] = json::array();
    Library_json["Transactions"] = json::array();

    for (const Book* book: List_Book) {
        Library_json["Books"].push_back(*book);
    }

    for (const Customer* customer: List_Customer) {
        json temp;
        if (customer->isVip()) {
            temp = *static_cast<const VipCustomer*>(customer);
        } else {
            temp = *customer;
        }
        temp["IsVip"] = customer->isVip();
        Library_json["Customers"].push_back(temp);
    }

    for (const Transaction* transaction: List_Transaction) {
        Library_json["Transactions"].push_back(*transaction);
    }

    std::ofstream output("Books.json");
    output << Library_json.dump(4);
}

Library::Library() :
    Total_Book(0),
    Total_Customer(0),
    Total_Transaction(0)
{
    deserialize();
}

Library::~Library() {
    serialize();
    for (Book* b : List_Book) {
        delete b;
    }
    List_Book.clear();
    List_Book.clear();
}

void Library::Clear_Storage() {
    json Reset;
    Total_Book = 0;

    for (Book* b : List_Book) {
        delete b;
    }
    List_Book.clear();

}

std::vector<Book*> Library::getbyName(const std::string& Name) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if(b->getName() == Name) {
            temp.push_back(b);
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyAuthor(const std::string& Author) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if(b->getAuthor() == Author) {
            temp.push_back(b);
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyGenre(const Genre& g) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        for (Genre genre: b->getGenre()) {
            if (genre == g) {
                temp.push_back(b);
            }
        }
    }
    return temp;
}

std::vector<Book*> Library::getbyRelease(const int& Year) const {
    std::vector<Book*> temp;
    for (Book* b: List_Book) {
        if (b->getYear() == Year) {
            temp.push_back(b);
        }
    }
    return temp;
}

Book* Library::getBookbyId(const int& id) const {
    for (Book* b: List_Book) {
        if (b->getId() == id) {
            return b;
        }
    }
    return nullptr;
}

Customer* Library::getCustomerbyId(const int& id) const {
    for (Customer* c: List_Customer) {
        if (c->getId() == id) {
            return c;
        }
    }
    return nullptr;
}

Transaction* Library::getTransactionbyId(const int& id) const {
    for (Transaction* t: List_Transaction) {
        if (t->getTransaction_id() == id) {
            return t;
        }
    }
    return nullptr;
}

void Library::display(const std::vector<Book*>& Book_List_Book) const {
    for (Book* b: Book_List_Book) {
        b->display();
    }
}

