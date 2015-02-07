/**
 * Name: FoodItem.cpp
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/03/2015
 * Version: 1.0.0
 */

 #include "FoodItem.h"

FoodItem::FoodItem(std::string _upc,  int _shelf_life, int _quantity)
 {
   upc = _upc;
   shelf_life = _shelf_life;
   quantity = _quantity;
 }

FoodItem::~FoodItem()
{

}

std::string FoodItem::get_upc() const
{
  return upc;
}

int FoodItem::get_shelf_life() const
{
  return shelf_life;
}

void FoodItem::decrement_shelf_life()
{
  shelf_life--;
}

bool FoodItem::operator<(const FoodItem& rhs) const
{
    return (upc.compare(rhs.upc) < 0);
}

bool FoodItem::operator==(const FoodItem& rhs) const
{
    return (upc.compare(rhs.upc) == 0);
}

bool FoodItem::operator!=(const FoodItem& rhs) const
{
    return (upc.compare(rhs.upc) != 0);
}

FoodItem & FoodItem::operator=(const FoodItem &rhs)
{
  upc = rhs.upc;
  shelf_life = rhs.shelf_life;
  quantity = rhs.quantity;
  return *this;
}
