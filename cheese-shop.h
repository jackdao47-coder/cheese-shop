#include "splashkit.h"
#include "splashkit-arrays.h"


struct cheese_data
{
    string name;
    double weight;
    int price_per_kg;
};

cheese_data new_cheese(string name = "", double weight = 0.0, int price_per_kg = 0);