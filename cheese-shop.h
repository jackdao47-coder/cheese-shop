#include "splashkit.h"
#include "splashkit-arrays.h"


struct cheese_data
{
    string name;
    double weight;
    int price_per_kg;
};

cheese_data new_cheese(string name = "", double weight = 0.0, int price_per_kg = 0);

string cheese_to_string(const cheese_data &cheese, bool full_details = false);