
#include <iostream>
#include <assert.h>
#include "TransactionSimulator.h"
#include "Warehouse.h"

using namespace std;

void test_fileread_debug();
void test_file();

int main()
{
//  test_fileread_debug();
    test_file();

}

void test_fileread_debug()
{
  {
    TransactionSimulator ts;

    string filename = "data1.txt";

    ts.run_simulation(filename);
  }
}


void test_file()
{
    {
        cout << endl;
        cout << "TESTING EMPTY WAREHOUSE... " << endl;
        
        //testing that nothing happens to an empty warehouse
        Warehouse wh("Salt Lake City");
        assert( wh.get_inventory_size() == 0 );
        assert( wh.item_count("012345") == 0 );
        assert( wh.item_count("011111") == 0 );
        assert( wh.item_count("022222") == 0 );
        assert( wh.item_count("033333") == 0 );
        assert( wh.item_count("044444") == 0 );
        assert( wh.get_inventory_size() == 0 );
        
        //remove from an empty warehouse
        wh.remove_food_item("012345", 1);
        assert( wh.item_count("012345") == 0 );
        assert( wh.get_inventory_size() == 0 );
        
        //remove expired from an empty warehouse
        wh.remove_expired();
        assert( wh.get_inventory_size() == 0 );

        cout << "DONE TESTING EMPTY WAREHOUSE... " << endl << endl;
    }
    
    
    {
        cout << "TESTING WAREHOUSE ADDING ITEMS/REMOVE EXPIRED... " << endl;
        
        //testing that nothing happens to an empty warehouse
        Warehouse wh("Salt Lake City");
        
        //start receiving food items with experation of 1 day
        wh.receive_food_item( "012345", 10, 1 );
        assert( wh.get_inventory_size() == 1);
        assert( wh.item_count("012345") == 10 );
        
        wh.receive_food_item( "543210", 10, 1 );
        assert( wh.get_inventory_size() == 2);
        assert( wh.item_count("543210") == 10 );

        //remove expired from warehouse should remove all
        wh.remove_expired();
        assert( wh.get_inventory_size() == 2 );
        assert( wh.item_count("543210") == 0 );
        assert( wh.item_count("012345") == 0 );

        //start receiving food items with experation > 1
        wh.receive_food_item( "000000", 1, 2 );
        assert( wh.get_inventory_size() == 3);
        assert( wh.item_count("000000") == 1 );
        
        wh.receive_food_item( "111111", 10, 100 );
        assert( wh.get_inventory_size() == 4);
        assert( wh.item_count("111111") == 10 );
        
        //remove expired from warehouse should remove all
        wh.remove_expired();
        assert( wh.get_inventory_size() == 4 );
        assert( wh.item_count("000000") == 1 );
        assert( wh.item_count("111111") == 10 );

        cout << "TESTING WAREHOUSE ADDING ITEMS/REMOVE EXPIRED... " << endl << endl;
    }
}