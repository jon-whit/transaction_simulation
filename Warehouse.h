/**
 * Name: Warehouse.h
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/08/2015
 * Version: 1.0.0
 */

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <map>
#include <deque>
#include "FoodItem.h"

class Warehouse
{
public:
    Warehouse(); // default constructor
    Warehouse(std::string _location);
    Warehouse(const Warehouse & other); // copy constructor

    std::string get_location() const;
    int get_inventory_size() const;
    void receive_food_item(std::string _upc, int n, int shelf_life);
    void remove_food_item(std::string _upc, int n);
    void remove_expired();
    int item_count(std::string upc) ;

    bool operator<(const Warehouse& rhs) const;
    bool operator==(const Warehouse& rhs) const;
    bool operator!=(const Warehouse& rhs) const;
    Warehouse& operator=(const Warehouse & rhs);

private:
    std::string location;
    std::map<std::string, std::deque<FoodItem> > inventory;
};

#endif
