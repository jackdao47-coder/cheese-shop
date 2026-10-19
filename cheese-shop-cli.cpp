#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

void print_cheese (cheese_data data) {
    write_line(data.name + ", " + to_string(data.weight) + "kg, $" + to_string(data.price_per_kg / 100) + " per kg");
}

int main()
{
   cheese_data cheese;

   cheese = new_cheese("cheddar", 1.5, 2000);

   print_cheese(cheese);

   return 0;
}