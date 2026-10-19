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
        cheese.price_per_kg / 100.0,
        total_cost(cheese) / 100);

    }
    else{
        return cheese.name;
    }
}

int total_cost(const cheese_data &cheese)
{
    return cheese.weight * cheese.price_per_kg;
}

double reduce_weight(cheese_data &cheese, double amount)
{
    if (amount <= 0)
    {
        return 0;
    }

    if (amount > cheese.weight)
    {
        amount = cheese.weight;
    }

    cheese.weight = cheese.weight - amount;
    return amount;
}

void increase_weight(cheese_data &cheese, double amount)
{
    if (amount > 0)
    {
        cheese.weight = cheese.weight + amount;
    }
}