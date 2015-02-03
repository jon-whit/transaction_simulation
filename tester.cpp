/**
 * Name: tester.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#include "FoodItem.h"
#include <iostream>
#include <cassert>

void test_constructors();
void test_setters();

int main()
{
    std::cout << "TESTS RUNNING..." << std::endl;

    test_constructors();
    test_setters();

    std::cout << "TESTS FINISHED..." << std::endl;
}

void test_constructors()
{
  std::cout << "TESTING CONSTRUCTORS" << std::endl;

  FoodItem item("1234", 2, "An item description");
  assert(item.get_upc() == "1234");
  assert(item.get_shelf_life() == 2);
  assert(item.get_name() == "An item description");

  FoodItem other = item; // invoke copy constructor
  assert(other.get_upc() == "1234");
  assert(other.get_shelf_life() == 2);
  assert(other.get_name() == "An item description");

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
