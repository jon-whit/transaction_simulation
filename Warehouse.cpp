/**
 * Name: Warehouse.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#include <string>
#include <iostream>
#include <queue>
#include "FoodItem.h"
#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse()
{

}

Warehouse::Warehouse(std::string _location)
{
    location = _location;
    std::map<std::string, std::queue<FoodItem> > inventory;
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
      inventory[_upc].push(f);
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
      inventory[_upc].pop();
  else
    for(int i = 0; i < n; i++)
      inventory[_upc].pop();

  #ifdef DEBUG
    cout << "REMOVING FOOD ITEMS FROM..." << endl;
    cout << "# Items Before Removal: " << items_inventory << endl;
    cout << "# Items After Removal: " << inventory[_upc].size() << endl << endl;
  #endif
}

void Warehouse::remove_expired()
{

  // iterate over each of the (key, value) pairs in the inventory
  map<string, queue<FoodItem> >::iterator it;
  for(it = inventory.begin(); it != inventory.end(); it++)
  {
      string key = it->first;

      cout << "Key: " << key << endl;

      // iteratre over each of the FoodItems
      int num_items = inventory[key].size();
      for(int i = 0; i < num_items; i++)
      {
          queue<FoodItem> q = inventory[key];
          FoodItem f = q.front();

          // remove the food item if it has expired
          int shelf_life = f.get_shelf_life();
          if (shelf_life <= 1)
            remove_food_item(key, 1);
          else
            f.set_shelf_life(--shelf_life);
      }
  }
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
