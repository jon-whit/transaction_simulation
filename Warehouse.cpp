/**
 * Name: Warehouse.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#include <string>
#include "FoodItem.h"
#include "Warehouse.h"
#include <set>
#include <boost/date_time/gregorian/gregorian.hpp>

Warehouse::Warehouse(std::string _location)
{
    location = _location;
    inventory_count = 0;
    std::set<FoodItem> inventory;
}

//Warehouse::Warehouse(const Warehouse & other)
//{
//    location = other.location;
//    inventory_count = other.inventory_count;
//    iterorator
//    std::set<FoodItem> inventory
//}

void Warehouse::set_location(std::string _location)
{
    location = _location;
}
bool Warehouse::add_food_item(const FoodItem & item)
{
    std::pair<std::set<FoodItem>::iterator, bool> ret = inventory.insert(item);
    if (ret.second)
        inventory_count++;
    return ret.second;
}
//bool remove_food_item(const &FoodItem);
//void remove_expired(boost::gregorian::date & current_date);
//std::string location;
//int inventory_count;
//    std::set<FoodItem> inventory;
std::string Warehouse::get_location() const
{
    return location;
}

int Warehouse::get_inventory_count() const
{
    return inventory_count;
}

bool Warehouse::operator<(const Warehouse& rhs) const
{
    return (location.compare(rhs.location) < 0);
}
