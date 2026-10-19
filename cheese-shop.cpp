#include "cheese-shop.h"
#include <format>
using std::format;

cheese_data new_cheese(string name, double weight, int price_per_kg)
{
    cheese_data cheese;
    cheese.name = name;
    cheese.weight = weight;
    cheese.price_per_kg = price_per_kg;
    return cheese;
}

string cheese_to_string(const cheese_data &cheese, bool full_details) {
    if (full_details){
        return std::format("{}: {:.2f} kg, ${:.2f}",
        cheese.name,
        cheese.weight,
        cheese.price_per_kg / 100.0);

    }
    else{
        return cheese.name;
    }
}

