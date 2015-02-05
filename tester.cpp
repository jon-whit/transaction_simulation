/**
 * Name: tester.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#include "FoodItem.h"
#include "Warehouse.h"
#include <iostream>
#include <cassert>

void test_constructors();
void test_setters();
void test_operator_less_than();
void test_add_food_item();
void test_operator_equal();
void test_remove_food_item();

int main()
{
    std::cout << "TESTS RUNNING..." << std::endl;

    test_constructors();
    test_setters();
    test_operator_less_than();
    test_add_food_item();
    test_operator_equal();
    test_remove_food_item();

    std::cout << "TESTS FINISHED..." << std::endl;
}

void test_constructors()
{
    std::cout << "TESTING CONSTRUCTORS" << std::endl;

    //FoodItem Construction
    {
        FoodItem item("1234", 2, "An item description");
        assert(item.get_upc() == "1234");
        assert(item.get_shelf_life() == 2);
        assert(item.get_name() == "An item description");

        FoodItem other = item; // invoke copy constructor
        assert(other.get_upc() == "1234");
        assert(other.get_shelf_life() == 2);
        assert(other.get_name() == "An item description");
    }

    //Warehouse Constructor
    {
        Warehouse house("Salt Lake City");
        assert(house.get_location() == "Salt Lake City");
        assert(house.get_inventory_count() == 0);
    }

    std::cout << "DONE TESTING CONSTRUCTORS" << std::endl;
}

void test_setters()
{
    std::cout << "TESTING SETTERS" << std::endl;

    FoodItem item("1234", 2, "An item description");
    item.set_upc("5678");
    item.set_shelf_life(4);
    item.set_name("A new item description");
    assert(item.get_upc() == "5678");
    assert(item.get_shelf_life() == 4);
    assert(item.get_name() == "A new item description");

    std::cout << "DONE TESTING SETTERS" << std::endl;
}

void test_operator_less_than()
{
    std::cout << "TESTING OPERATOR '<'" << std::endl;

    //Food Item
    {
    FoodItem item("1234", 2, "An item description");
    FoodItem item2("12345", 3, "An item description for another");
    assert(item < item2);

    item.set_upc("54321");
    item2.set_upc("12345");
    assert(item2 < item);
    }

    //Warehouse
    {
        Warehouse house("1234");
        Warehouse house2("12345");
        assert(house < house2);
    }

    std::cout << "DONE TESTING OPERATOR '<'" << std::endl;
}

void test_operator_equal()
{
    std::cout << "TESTING OPERATOR '==' & '!='" << std::endl;

    //Food Item
    {
    FoodItem item("12345", 2, "An item description");
    FoodItem item2("12345", 3, "An item description for another");
    assert(item == item2);

    item.set_upc("54321");
    item2.set_upc("12345");
    assert(item2 != item);
    }

    //Warehouse
    {
        Warehouse house("1234");
        Warehouse house2("12345");
        assert(house != house2);

        house.set_location("12345");
        assert(house == house2);
    }

    std::cout << "DONE TESTING OPERATOR '==' & '!='" << std::endl;
}

void test_add_food_item()
{
    std::cout << "TESTING ADD FOOD ITEM" << std::endl;

    Warehouse house("Ogden");
    std::set<FoodItem> test_set;

    FoodItem item("1234", 3, "Description");
    test_set.insert(item);
    FoodItem item2("12345", 3, "Description");
    test_set.insert(item2);
    FoodItem item3("12345", 3, "Description");
    test_set.insert(item3);

    assert(house.add_food_item(item));
    assert(house.get_inventory_count() == 1);
    assert(house.add_food_item(item2));
    assert(house.get_inventory_count() == 2);
    assert(house.add_food_item(item3) == 0);
    assert(house.get_inventory_count() == 2);

    std::set<FoodItem> inventory;
    inventory = house.get_inventory();

    assert(inventory.size() == test_set.size());

    std::set<FoodItem>::iterator it;
    for (it = inventory.begin(); it != inventory.end(); ++it)
    {
        FoodItem f = *it;
        assert (test_set.find(f) != inventory.end());

    }

    std::cout << "DONE TESTING ADD FOOD ITEM" << std::endl;
}

void test_remove_food_item()
{
    std::cout << "TESTING REMOVE FOOD ITEM" << std::endl;
    
    Warehouse house("Ogden");
    std::set<FoodItem> test_set;
    
    FoodItem item("1234", 3, "Description");
    test_set.insert(item);
    FoodItem item2("12345", 3, "Description");
    test_set.insert(item2);
    FoodItem item3("12345", 3, "Description");
    test_set.insert(item3);
    
    assert(house.add_food_item(item));
    assert(house.get_inventory_count() == 1);
    assert(house.add_food_item(item2));
    assert(house.get_inventory_count() == 2);
    assert(house.add_food_item(item3) == 0);
    assert(house.get_inventory_count() == 2);
    
    assert(house.remove_food_item(item));
    test_set.erase(item);
    assert(house.get_inventory_count() == 1);
    assert(house.remove_food_item(item2));
    test_set.erase(item2);
    assert(house.get_inventory_count() == 0);
    
    std::set<FoodItem> inventory;
    inventory = house.get_inventory();
    
    assert(inventory.size() == test_set.size());
    
    std::set<FoodItem>::iterator it;
    for (it = inventory.begin(); it != inventory.end(); ++it)
    {
        FoodItem f = *it;
        assert (test_set.find(f) != inventory.end());
        
    }
    
    std::cout << "DONE TESTING REMOVE FOOD ITEM" << std::endl;
}
