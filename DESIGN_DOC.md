#Design Documentation


##Resources:
###FoodItems
------------
The FoodItems transfered between warehouses can be represented as a class with attributes like those shown in *Table 1* . Each FoodItem object has a Universal Product Code (UPC) that uniquely identifies the object.

|  attribute | type                  |
|:----------:|-----------------------|
| UPC        | string                |
| shelf_life | int                   |
| name       | string |
Table 1: FoodItem attributes

###Warehouses
-------------
Each warehouse in a company is identified via the name of the city (string) where the warehouse is located. A map datastructure would be a great way to stores these associations. Each key in the map could be a pointer to a Warehouse object. *Table 2* shows a possible model for this layout. Each Warehouse object will store its location and an inventory of `FoodItem` objects. A Warehouse object must be able to add food items and remove food items from its inventory.

|     key    | value                     |
|:----------:|---------------------------|
| Columbus   | *Warehouse("Columbus")   |
| Scottsdale | *Warehouse("Scottsdale") |
| Tacoma     | *Warehouse("Tacoma")     |
Table 2: Representing warehouses.

##Operations:
