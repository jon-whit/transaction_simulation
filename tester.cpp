#include <iostream>
#include "TransactionSimulator.h"

using namespace std;

void test_fileread_debug();

int main()
{
  cout << "TESTS STARTED..." << endl;

  test_fileread_debug();

  cout << "TESTS FINISHED..." << endl;
}

void test_fileread_debug()
{
  {
    TransactionSimulator ts;

    string filename = "data1.txt";

    // print out the contents of the file if DEBUG is defined by the
    // pre-processor.
    //ts.run_simulation(filename);
  }
}
