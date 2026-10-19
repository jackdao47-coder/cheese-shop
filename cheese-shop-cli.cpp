#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

void print_cheese (cheese_data data) {
    write_line(cheese_to_string(data, true));
}

int main()
{
   cheese_data cheese;

   cheese = new_cheese("cheddar", 1.5, 2000);

   print_cheese(cheese);

   return 0;
}