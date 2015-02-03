/**
 * Name: FoodItem.h
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

class FoodItem
{
public:
  FoodItem(std::string upc, int, std::string name); // constructor
  FoodItem(const FoodItem &other); // copy constructor

  void set_upc(std::string upc); // setter for UPC
  std::string get_upc() const; // getter for UPC. doesn't modify this.
  void set_shelf_life(int shelf_life); // setter for shelf_life
  int get_shelf_life() const; // getter for shelf_life. doesn't modify this.
  void set_name(std::string name); // setter for name
  std::string get_name() const; // getter for name. doesn't modify this.

private:
  std::string upc;
  int shelf_life;
  boost::gregorian::date expiration_date;
  std::string name;
};

#endif
