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

      /*std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));

      // get UPC
      string upc = params[4];

      // get shelf life using Boost's string -> int cast
      int shelf_life = boost::lexical_cast<int>(params[7]);

      add_food_item();*/
    } else if (instruction == "Warehouse") {

      // parse the warehouse location
      std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));
      string location = params[2];

      // add it to the map of warehouses
      add_warehouse(location);

    } else if (instruction == "Receive" || instruction == "Request") {
      /*
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
      if (instruction == "Receive")
        warehouses[location].receive_food_item(upc, n, shelf_life);
      else
        warehouses[location].remove_food_item(upc, n);*/

    } else if (instruction == "Next") {
      // for each warehouse in warehouses:
      //    decrement each inventory items shelf life.
      //    remove expired items (i.e. if shelf life = 0)

      // for(Warehouse wh : warehouses)
      //      warehouse.remove_expired();

      // let remove_expired take care of the rest..
    } else {
      // get_unstocked_products();
      // get_wellstocked_products();
    }
  }
}

void TransactionSimulator::add_food_item(string upc)
{
  //shelf_lives[upc] = shelf_life;
  //names[upc] = name;

  #ifdef DEBUG
    //cout << "ADDED FOOD ITEM: '" << upc << "'" << endl;


    //cout << "ADDED FOOD ITEM: " << upc << endl;
    //cout << "Name: " << name << endl;
    //cout << "Shelf Life: " << shelf_life << endl;
    //cout << "'" << food_items.size() << "' ITEM(S) TOTAL" << endl;
  #endif
}

void TransactionSimulator::add_warehouse(string location)
{
  Warehouse h(location);
  warehouses[location] = h;

  #ifdef DEBUG
    cout << "ADDED WAREHOUSE: '" << location << "'" << endl;
    cout << "'" << warehouses.size() << "' WAREHOUSE(S) TOTAL" << endl;
  #endif
}

void TransactionSimulator::get_unstocked_products() const
{

}

void TransactionSimulator::get_wellstocked_products() const
{

}
