#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "TransactionSimulator.h"
#include "Warehouse.h"
#include "FoodItem.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

TransactionSimulator::TransactionSimulator()
{
  map<string, int> shelf_lives;
  map<string, string> names;
  map<string, Warehouse> warehouses;
  set<FoodItem> unstocked_products;
  set<FoodItem> wellstocked_products;
}

void TransactionSimulator::run_simulation(std::string _filename)
{
  ifstream infile( _filename );

  for( string line; getline( infile, line ); )
  {

    // create a stringstream on the current line to parse it
    stringstream ss(line);
    string instruction;
    ss >> instruction;

    // check the instruction and run the operation associated with that
    // instruction.
    if (instruction == "FoodItem") {

      #ifdef DEBUG
        cout << line << endl;
      #endif

      std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));

      // get UPC
      string upc = params[4];

      // get shelf life using Boost's string -> int cast
      int shelf_life = boost::lexical_cast<int>(params[8]);

        string name = line.substr(line.find("Name:") + 6);

      add_food_item(upc, name, shelf_life);
    } else if (instruction == "Warehouse") {

      #ifdef DEBUG
        cout << line << endl;
      #endif

      // parse the warehouse location
      std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));
      string location = params[2];

      // add it to the map of warehouses
      add_warehouse(location);

    } else if (instruction == "Receive:" || instruction == "Request:") {

      #ifdef DEBUG
        cout << line << endl;
      #endif

      std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));

      // get UPC
      string upc = params[1];

      // get number of items to add
      int n = boost::lexical_cast<int>(params[2]);

      // get Warehouse location
      string location = params[3];

      // get the shelf life for that product
      int shelf_life = shelf_lives[upc];

      // add or remove the food item to the warehouses inventory depending
      // on the instruction
      if (instruction == "Receive:")
        warehouses[location].receive_food_item(upc, n, shelf_life);
      else
        warehouses[location].remove_food_item(upc, n);

    } else if (instruction == "Next") {

      cout << line << endl;

      // iteratre over each of the warehouses
      map<string, Warehouse >::iterator it;
      for(it = warehouses.begin(); it != warehouses.end(); it++)
      {
          string location = it->first;

          warehouses[location].remove_expired();
      }

      #ifdef DEBUG
        cout << "END NEXT DAY" << endl << endl;
      #endif

    } else if (instruction == "End") {
      // get_unstocked_products();
      // get_wellstocked_products();
    }
  }
}

void TransactionSimulator::add_food_item(string upc, string name, int shelf_life)
{
  shelf_lives[upc] = shelf_life;
  names[upc] = name;

  #ifdef DEBUG
    cout << "ADDED FOOD ITEM: " << upc << endl;
    cout << "Name: " << name << endl;
    cout << "Shelf Life: " << shelf_life << endl << endl;
//    cout << "'" << food_items.size() << "' ITEM(S) TOTAL" << endl;
  #endif
}

void TransactionSimulator::add_warehouse(string location)
{
  Warehouse h(location);
  warehouses[location] = h;

  #ifdef DEBUG
    cout << "ADDED WAREHOUSE: " << location << endl;
    cout << warehouses.size() << " WAREHOUSE(S) TOTAL" << endl << endl;
  #endif
}

void TransactionSimulator::get_unstocked_products() const
{

}

void TransactionSimulator::get_wellstocked_products() const
{

}
