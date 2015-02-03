/**
 * Name: FoodItem.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

 #include "FoodItem.h"

FoodItem::FoodItem(std::string _upc, int _shelf_life, std::string _name)
 {
   upc = _upc;
   shelf_life = _shelf_life;
   name = _name;
 }

FoodItem::FoodItem(const FoodItem &other)
{
  upc = other.upc;
  shelf_life = other.shelf_life;
  name = other.name;
}

void FoodItem::set_upc(std::string _upc)
{
  upc = _upc;
}

std::string FoodItem::get_upc()
{
  return upc;
}

void FoodItem::set_shelf_life(int _shelf_life)
{
    shelf_life = _shelf_life;
}

int FoodItem::get_shelf_life()
{
  return shelf_life;
}

void FoodItem::set_name(std::string _name)
{
    name = _name;
}

std::string FoodItem::get_name()
{
  return name;
}
