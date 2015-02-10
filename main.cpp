/**
 * Name: main.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/08/2015
 * Version: 1.0.0
 */

#include "TransactionSimulator.h"

using namespace std;

int main (int argc, char* argv[])
{

    // create the TransactionSimulator object
    TransactionSimulator ts;

    // get the file name from the parameter
    string filename = argv[1];

    // run the simulation
    ts.run_simulation(filename);
}
