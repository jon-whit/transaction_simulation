#include "TransactionSimulator.h"

using namespace std;

void test_fileread_debug();

int main()
{
  test_fileread_debug();
}

void test_fileread_debug()
{
  {
    TransactionSimulator ts;

    string filename = "data1.txt";

    ts.run_simulation(filename);
  }
}
