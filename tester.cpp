#include <iostream>
#include "TransactionSimulator.h"

using namespace std;

void test_fileread_debug();
void test_add_warehouse();

int main()
{
  cout << "TESTS STARTED..." << endl << endl;

  test_fileread_debug();
  test_add_warehouse();

  cout << "TESTS FINISHED..." << endl << endl;
}

void test_fileread_debug()
{
  {
    cout << "TEST READING data1.txt BEGIN.." << endl << endl;

    TransactionSimulator ts;

    string filename = "data1.txt";

    // print out the contents of the file if DEBUG is defined by the
    // pre-processor.
    ts.run_simulation(filename);

    cout << endl << "TEST READING data1.txt FINISHED.." << endl << endl;;
  }
}

void test_add_warehouse()
{
  {
    cout << "TEST ADD WAREHOUSE BEGIN.." << endl << endl;;
    TransactionSimulator ts;

    ts.add_warehouse("Salt Lake City");
    ts.add_warehouse("New York City");
    ts.add_warehouse("San Jose");

    cout << endl << "TEST ADD WAREHOUSE FINISHED.." << endl << endl;
  }
}
