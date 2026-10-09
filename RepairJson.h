#ifndef REPAIRJSON_H
#define REPAIRJSON_H

#include "json.hpp"
#include <fstream>

using nlohmann::json;

void Repair() {
    json Repair;

    Repair["Book"] = "[]";

    std::ofstream file("Books.json");
    file << Repair.dump(4);
}

#endif