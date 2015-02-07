/**
 * Name: TransactionSimluator.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/05/2015
 * Version: 1.0.0
 */

#ifndef TRANSIM_H
#define TRANSIM_H

#include "FoodItem.h"
#include "Warehouse.h"
#include <string>
#include <map>

class TransactionSimulator
{
public:
    TransactionSimulator(); // default constructor

    void run_simulation(std::string file_name);
    void add_food_item(std::string _upc, std::string _name, int _shelf_life);
    void add_warehouse(std::string _location);
    void get_unstocked_products() const;
    void get_wellstocked_products() const;

private:
  std::map<std::string, int> shelf_lives;
  std::map<std::string, std::string> names;
  std::map<std::string, Warehouse> warehouses;
};

#endif
