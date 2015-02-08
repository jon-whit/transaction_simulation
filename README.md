# transaction_simulation
An application to perform an analysis of inventory for a small wholesale food products company.

## Building
-----------
To build our application simply invoke `g++ main.cpp FoodItem.cpp Warehouse.cpp TransactionSimulator.cpp`. This will create an object file `a.out` that executes the main entry point found in the `main.cpp` source file.

DO NOT COMPILE THE `tester.cpp` and `main.cpp` source files together. This will cause an issue as they both
define main entry points.

## Running the Application
--------------------------
Once you have built the application using the command above, run the file using
```
$ ./a.out filename
```

For example, with the data files provided for this assignment you would invoke the commands:
```
$ ./a.out data1.txt
$ ./a.out data2.txt
$ ./a.out data3.txt
```
