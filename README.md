# transaction_simulation
An application to perform an analysis of inventory for a small wholesale food products company.

## Building
-----------
To build our application run the command below:

```
g++ main_application.cpp TransactionSimulator.cpp Warehouse.cpp FoodItem.cpp -l boost_date_time
```

This will create an object file `a.out` that executes the main entry point found in the
`main_application.cpp` source file. The `-l` flag is needed so that g++ knows to link
with the boost library found in the includes folder.

## Design Model
Please see our DESIGN_DOC for more information on our class model.
