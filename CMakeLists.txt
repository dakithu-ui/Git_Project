cmake_minimum_required(VERSION 3.16)

project(Library_Book_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Library_Book_Project main.cpp
    Book.h
    json.hpp
    Book.cpp



    Library.h
    Library.cpp
    BookManager.h
    Customer.cpp
    Customer.h
    RepairJson.h
    Transaction.h
    Transaction.cpp
    VipCustomer.cpp
    VipCustomer.h

)

include(GNUInstallDirs)
install(TARGETS Library_Book_Project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
