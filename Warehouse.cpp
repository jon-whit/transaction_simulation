/**
 * Name: Warehouse.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/08/2015
 * Version: 1.0.0
 */

#include <string>
#include <iostream>
#include <deque>
#include "FoodItem.h"
#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse()
{

}

Warehouse::Warehouse(std::string _location)
{
    location = _location;
    std::map<std::string, std::deque<FoodItem> > inventory;
}

Warehouse::Warehouse(const Warehouse & other)
{
    location = other.location;
    inventory = other.inventory;
}

void Warehouse::receive_food_item(std::string _upc, int n, int shelf_life)
{
    // push n items into the inventory
    for (int i = 0; i < n; i++)
    {
      FoodItem f(_upc, shelf_life, n);
      inventory[_upc].push_back(f);
    }

    #ifdef DEBUG
        cout << "ADDED FOOD ITEM: " << _upc << " to warehouse " << location << endl;
        cout << "Quantity: " << n << endl << endl;
    #endif
}

void Warehouse::remove_food_item(std::string _upc, int n)
{
  int items_inventory = inventory[_upc].size();

  if (items_inventory < n)
    for(int i = 0; i < items_inventory; i++)
      inventory[_upc].pop_front();
  else
    for(int i = 0; i < n; i++)
      inventory[_upc].pop_front();

  #ifdef DEBUG
    cout << "REMOVING FOOD ITEMS FROM..." << endl;
    cout << "# Items Before Removal: " << items_inventory << endl;
    cout << "# Items After Removal: " << inventory[_upc].size() << endl << endl;
  #endif
}

void Warehouse::remove_expired()
{

  // iterate over each of the (key, value) pairs in the inventory
  map<string, deque<FoodItem> >::iterator it;
  for(it = inventory.begin(); it != inventory.end(); it++)
  {
      string upc = it->first;

      #ifdef DEBUG
        cout << "Warehouse: " << location << endl;
        cout << "Upc: " << upc << endl;
      #endif

      // iteratre over each of the FoodItems
      int num_items = inventory[upc].size();
      for(int i = 0; i < num_items; i++)
      {
          inventory[upc][i].decrement_shelf_life();
          if (inventory[upc][i].get_shelf_life() <= 0)
            remove_food_item(upc, 1);
      }
  }
}

std::string Warehouse::get_location() const
{
    return location;
}

int Warehouse::item_count(string upc)
{

  if ( m.find("f") == m.end() ) {
    return 0;
  } else {
    int count = inventory[upc].size();
    return count;
  }
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
