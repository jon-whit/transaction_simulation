all:
	g++ main.cpp TransactionSimulator.cpp Warehouse.cpp FoodItem.cpp

clean:
	rm -rf *.o *.out
