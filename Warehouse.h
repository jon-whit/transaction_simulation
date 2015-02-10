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
    Warehouse(std::string _location); // constructor with string location
    Warehouse(const Warehouse & other); // copy constructor

    std::string get_location() const; // returns the string location name
    int get_inventory_size() const; // returns the int size of inventory
    void receive_food_item(std::string _upc, int n, int shelf_life); // adds food item, params - string upc, int number of items, int shelf life
    void remove_food_item(std::string _upc, int n); // removes food item, params - string upc, int number of items to remove
    void remove_expired(); // removes all old items
    int item_count(std::string upc) ; //returns the count, params - sting upc, retuns - int amount

    bool operator<(const Warehouse& rhs) const;
    bool operator==(const Warehouse& rhs) const;
    bool operator!=(const Warehouse& rhs) const;
    Warehouse& operator=(const Warehouse & rhs);

private:
    std::string location;
    std::map<std::string, std::deque<FoodItem> > inventory;
};

#endif
