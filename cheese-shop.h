#include "splashkit.h"
#include "splashkit-arrays.h"


struct cheese_data
{
    string name;
    double weight;
    int price_per_kg;
};

struct order_data
{
    string cheese_name;
    double weight;
    double weight_supplied;
};

struct cheese_shop_data
{
    dynamic_array<cheese_data> cheeses;
    dynamic_array<order_data> orders;
};

cheese_data new_cheese(string name = "", double weight = 0.0, int price_per_kg = 0);

string cheese_to_string(const cheese_data &cheese, bool full_details = false);

int total_cost(const cheese_data &cheese);

double reduce_weight(cheese_data &cheese, double amount);

void increase_weight(cheese_data &cheese, double amount);

void add_cheese(cheese_shop_data &shop, const cheese_data &new_cheese);

bool cheese_valid(const cheese_data &cheese, string &error_message);

int find_cheese(const cheese_shop_data &shop, const string &name);

order_data new_order(string cheese_name = "", double weight = 0.0);

string order_to_string(const order_data &order);

void add_order(cheese_shop_data &shop, const order_data &order);

bool order_valid(const order_data &order, string &error_message);