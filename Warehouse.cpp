/**
 * Name: Warehouse.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#include <string>
#include "FoodItem.h"
#include "Warehouse.h"

Warehouse::Warehouse()
{

}

Warehouse::Warehouse(std::string _location)
{
    location = _location;
    std::map<std::string, std::vector<FoodItem> > inventory;
}

Warehouse::Warehouse(const Warehouse & other)
{
  location = other.location;
  inventory = other.inventory;
}

bool Warehouse::receive_food_item(std::string _upc, int n)
{

}

bool Warehouse::remove_food_item(std::string _upc, int n)
{

}

void Warehouse::remove_expired()
{

}

std::string Warehouse::get_location() const
{
    return location;
}

bool Warehouse::operator<(const Warehouse& rhs) const
{
    return (location.compare(rhs.location) < 0);
}

bool Warehouse::operator==(const Warehouse& rhs) const
{
    return (location.compare(rhs.location) == 0);
}

bool Warehouse::operator!=(const Warehouse& rhs) const
{
    return (location.compare(rhs.location) != 0);
}

Warehouse & Warehouse::operator=(const Warehouse & rhs)
{
    location = rhs.location;
    inventory = rhs.inventory;
    return *this;
}
