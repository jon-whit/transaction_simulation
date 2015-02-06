#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "TransactionSimulator.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

void TransactionSimulator::run_simulation(std::string _filename)
{
  ifstream infile( _filename );

  for( string line; getline( infile, line ); )
  {
    #ifdef DEBUG
      cout << line << endl;
    #endif

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

    } else if (instruction == "Start") {

    } else if (instruction == "Receive") {

      std::vector<std::string> params;
      boost::split(params, line, boost::is_any_of(" "));

      // get UPC
      string upc = params[1];

      // get number of items to add
      int n = boost::lexical_cast<int>(params[2]);

      // get Warehouse location
      string location = params[3];

      // get the shelf life for that product
      //int shelf_life = shelf_lives[upc];

      // add the food item to the warehouses inventory
      //warehouses[location].add_food_item(upc, n, shelf_life);

    } else if (instruction == "Request") {

    } else if (instruction == "Next") {
      // for each warehouse in warehouses:
      //    decrement each inventory items shelf life.
      //    remove expired items (i.e. if shelf life = 0)

      // for(Warehouse wh : warehouses)
      //      warehouse.remove_expired();

      // let remove_expired take care of the rest..
    } else {
      // get_unstocked_products();
      // get_wellstocked_proudcts();
    }
  }
}
