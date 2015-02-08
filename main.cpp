/**
 * Name: FoodItem.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/07/2015
 * Version: 1.0.0
 */

#include "TransactionSimulator.h"

using namespace std;

int main (int argc, char* argv[])
{

    TransactionSimulator ts;
    
    string filename = argv[1];
    
    ts.run_simulation(filename);
}