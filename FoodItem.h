/**
 * Name: FoodItem.h
 * Authors: Jonathan Whitaker & Christopher Hartley
 * Last Modified: 02/08/2015
 * Version: 1.0.0
 */

#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>

class FoodItem
{
public:
    FoodItem(std::string _upc, int _shelf_life, int _quantity); // constructor
    ~FoodItem(); // destructor

    std::string get_upc() const; // getter for UPC. doesn't modify this.
    std::string get_name() const; // getter for name. doesn't modify this.
    int get_shelf_life() const; // getter for shelf_life. doesn't modify this.
    void decrement_shelf_life(); // decrements the shelf life of this FoodItem.
    int get_quantity() const; // getter for the quantity. doesn't modify this.

    bool operator<(const FoodItem& rhs) const; // compares based on UPC
    bool operator==(const FoodItem& rhs) const; // checks equality between UPC
    bool operator!=(const FoodItem& rhs) const; // complement of ==
    FoodItem & operator=(const FoodItem &rhs); 


private:
    std::string upc;
    std::string name;
    int shelf_life;
    int quantity;
};

#endif
