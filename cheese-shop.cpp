#include "cheese-shop.h"

cheese_data new_cheese(string name, double weight, int price_per_kg)
{
    cheese_data cheese;
    cheese.name = name;
    cheese.weight = weight;
    cheese.price_per_kg = price_per_kg;
    return cheese;
}