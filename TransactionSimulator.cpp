#include <ifstream>
#include <iostream>
#include "TransactionSimulator.h"

using namespace std;

void TransactionSimulator::run_simulation(std::string _filename)
{
  ifstream infile( _filename );

  for( string line; getline( infile, line ); )
  {
    #ifdef (DEBUG)
      cout << line << endl;
    #endif
  }
}
