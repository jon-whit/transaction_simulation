/**
 * Name: Warehouse.h
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include "FoodItem.h"
#include <set>
#include <boost/date_time/gregorian/gregorian.hpp>

class Warehouse
{
public:
    Warehouse(std::string _location); // default constructor
    ~Warehouse(); // destructor

//    Warehouse(const Warehouse & other);

    void set_location(std::string _location);
    std::string get_location() const;
    bool add_food_item(const FoodItem & item);

//    bool remove_food_item(const &FoodItem);
//    void remove_expired(boost::gregorian::date & current_date);

    std::set<FoodItem> get_inventory() const;
    int get_inventory_count() const;

    bool operator<(const Warehouse& rhs) const;
    bool operator==(const Warehouse& rhs) const;
    bool operator!=(const Warehouse& rhs) const;

private:
    std::string location;
    int inventory_count;
    std::set<FoodItem> inventory;
};

#endif
