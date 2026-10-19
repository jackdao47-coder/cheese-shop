#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

#include <format>
using std::format;


enum main_menu_option
{
    EXIT_MAIN_MENU,
    ADD_CHEESE_MENU,
    PRINT_STOCK_LIST_MENU
};

void print_cheese (const cheese_data &cheese, bool with_full_details) {
    write_line(cheese_to_string(cheese, with_full_details));
}

cheese_data read_cheese()
{
    cheese_data result;

    result.name = read_string("Enter Cheese name: ");
    result.weight = read_double("Enter weight in stock (kg): ");
    result.price_per_kg = read_integer("Enter price per kg (cents): ");

    return result;
}

void handle_add_cheese(cheese_shop_data &shop)
{
    cheese_data cheese = read_cheese();
    add_cheese(shop, cheese);
}

main_menu_option read_main_menu_option(){
    write_line("0. Exit");
    write_line("1. Add cheese");
    write_line("2. Print cheese list");

    return (main_menu_option)read_integer("Select an option (0-2): ", 0, 2);
}

void print_stock_list(const cheese_shop_data &shop)
{

    if(shop.cheeses.length() == 0)
    {
        write_line("No cheese");
        return;
    }

    write_line();
    write_line("======================");
    write_line("Cheese stock list: ");
    write_line("======================");

    for (int i = 0; i < shop.cheeses.length(); i++)
    {
        print_cheese(shop.cheeses[i], true);
    }

    write_line("======================");
    write_line();
}

int main()
{
   cheese_shop_data shop;
   main_menu_option choice;

   do
   {
    choice = read_main_menu_option();

    switch(choice)
    {
        case EXIT_MAIN_MENU:
            write_line("Exiting...");
            break;
        case ADD_CHEESE_MENU:
            handle_add_cheese(shop);
            break;
        case PRINT_STOCK_LIST_MENU:
            print_stock_list(shop);
            break;
    }
   } while (choice != EXIT_MAIN_MENU);

   return 0;

}