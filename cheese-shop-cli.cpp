#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

#include <format>
using std::format;


enum main_menu_option
{
    EXIT_MAIN_MENU,
    ADD_CHEESE_MENU,
    EDIT_CHEESE_MENU,
    PRINT_STOCK_LIST_MENU,
    FIND_CHEESE_MENU,
    ADD_ORDER_MENU,
    PRINT_ORDERS_MENU
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

void edit_cheese(cheese_data &cheese){

    cheese_data original = cheese;

    write_line("Editing cheese: " + cheese_to_string(cheese, true));

    if(read_bool("Do you want to edit the name? [true/false]: "))
    {
        cheese.name = read_string("Enter a new cheese name: ");

    }
    if(read_bool("Do you want to edit the weight? [true/false]: "))
    {
        cheese.weight = read_double("Enter new weight in stock: ");
        
    }
    if(read_bool("Do you want to edit the price? [true/false]: "))
    {
        cheese.price_per_kg = read_integer("Enter the new price per kg (cents): ");
        
    }

    string error_message;
      if (!cheese_valid(cheese, error_message))
      {
          write_line("Invalid cheese: " + error_message);
          write_line("Changes discarded.");
          cheese = original;
      }
}

void print_cheese_list (const dynamic_array<cheese_data> &cheeses, bool with_ids) {

    for(int i = 0; i < cheeses.length(); i++){
        cheese_data cheese = cheeses[i];
        if (with_ids)
        {
            write(format("{}: ", i + 1));
        }
        print_cheese(cheese, true);
    }
}

int select_cheese(const dynamic_array<cheese_data> &cheeses) {
    if (cheeses.length() == 0)
    {
        write_line("No cheese in stock");
        return -1;
    }

    write_line("0: select none");

    print_cheese_list(cheeses, true);

    return read_integer("Select cheese (0 - " + to_string(cheeses.length()) + "): ", 0, cheeses.length()) -1;
}

void handle_edit_cheese(cheese_shop_data &shop){
    int index = select_cheese(shop.cheeses);

    if(index == -1) return;

    edit_cheese(shop.cheeses[index]);
}

void handle_add_cheese(cheese_shop_data &shop)
{
    cheese_data cheese = read_cheese();
    add_cheese(shop, cheese);
}

main_menu_option read_main_menu_option(){
    write_line("0. Exit");
    write_line("1. Add cheese");
    write_line("2. Edit cheese");
    write_line("3. Print cheese list");
    write_line("4. Find cheese");
    write_line("5. Add order");
    write_line("6. Print orders");

    return (main_menu_option)read_integer("Select an option (0-6): ", 0, 6);

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

void handle_find_cheese(const cheese_shop_data &shop)
{
    string name = read_string("Enter the cheese name to find: ");
    int index = find_cheese(shop, name);

    if (index == -1)
    {
        write_line("No cheese found with that name");
    }
    else
    {
        print_cheese(shop.cheeses[index], true);
    }
}

order_data read_order()
{
    order_data order;
    string error_message;
    bool valid = false;

    while (!valid)
    {
        order.cheese_name = read_string("Enter cheese name: ");
        order.weight = read_double("Enter weight ordered (kg): ");
        order.weight_supplied = 0;

        valid = order_valid(order, error_message);
        if (!valid)
        {
            write_line("Invalid order: " + error_message);
        }
    }

    return order;
}

void handle_add_order(cheese_shop_data &shop)
{
    order_data order = read_order();
    add_order(shop, order);
}

void print_order_list(const cheese_shop_data &shop)
{
    if (shop.orders.length() == 0)
    {
        write_line("No orders");
        return;
    }

    write_line();
    write_line("======================");
    write_line("Order list: ");
    write_line("======================");

    for (int i = 0; i < shop.orders.length(); i++)
    {
        write_line(order_to_string(shop.orders[i]));
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
        case EDIT_CHEESE_MENU:
            handle_edit_cheese(shop);
            break;
        case PRINT_STOCK_LIST_MENU:
            print_stock_list(shop);
            break;
        case FIND_CHEESE_MENU:
            handle_find_cheese(shop);
            break;
        case ADD_ORDER_MENU:
            handle_add_order(shop);
            break;
        case PRINT_ORDERS_MENU:
            print_order_list(shop);
            break;
    }
   } while (choice != EXIT_MAIN_MENU);

   return 0;

}