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
        return std::format("{}: {:.2f} kg, ${:.2f} per kg, total ${:.2f}",
        cheese.name,
        cheese.weight,
        cheese.price_per_kg / 100.0,
        total_cost(cheese) / 100.0);

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

void add_cheese(cheese_shop_data &shop, const cheese_data &cheese)
{
    shop.cheeses.add(cheese);
}

bool cheese_valid(const cheese_data &cheese, string &error_message)
{
    error_message = "";

    if (cheese.name == "")
    {
        error_message += "Name is empty. ";
    }
    if (cheese.weight < 0)
    {
        error_message += "Weight cannot be negative. ";
    }
    if (cheese.price_per_kg < 0)
    {
        error_message += "Price cannot be negative. ";
    }

    return error_message == "";
}

int find_cheese(const cheese_shop_data &shop, const string &name)
{
    for (int i = 0; i < shop.cheeses.length(); i++)
    {
        if (to_lowercase(shop.cheeses[i].name) == to_lowercase(name))
        {
            return i;
        }
    }

    return -1;
}

order_data new_order(string cheese_name, double weight)
{
    order_data order;
    order.cheese_name = cheese_name;
    order.weight = weight;
    order.weight_supplied = 0;
    return order;
}

string order_to_string(const order_data &order)
{
    return std::format("{}: {:.2f} kg ordered, {:.2f} kg supplied",
        order.cheese_name,
        order.weight,
        order.weight_supplied);
}

void add_order(cheese_shop_data &shop, const order_data &order)
{
    shop.orders.add(order);
}

bool order_valid(const order_data &order, string &error_message)
{
    error_message = "";

    if (order.cheese_name == "")
    {
        error_message += "Cheese name is empty. ";
    }
    if (order.weight <= 0)
    {
        error_message += "Weight must be greater than 0. ";
    }

    return error_message == "";
}