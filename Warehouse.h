/**
 * Name: Warehouse.h
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <map>
#include <vector>
#include "FoodItem.h"

class Warehouse
{
public:
    Warehouse(); // default constructor
    Warehouse(std::string _location);
    Warehouse(const Warehouse & other); // copy constructor

    std::string get_location() const;
    bool receive_food_item(std::string _upc, int n);
    bool remove_food_item(std::string _upc, int n);
    void remove_expired();

    bool operator<(const Warehouse& rhs) const;
    bool operator==(const Warehouse& rhs) const;
    bool operator!=(const Warehouse& rhs) const;
    Warehouse& operator=(const Warehouse & rhs);

private:
    std::string location;
    std::map<std::string, std::vector<FoodItem> > inventory;
};

#endif
