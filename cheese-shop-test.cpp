cheese_data cheese;
   cheese_shop_data shop;

   cheese = new_cheese("cheddar", 1.5, 2000);

   print_cheese(cheese);

   print_cheese(new_cheese("cheddar", 1.5, 2000));
   print_cheese(new_cheese("brie", 0.25, 3200));
   print_cheese(new_cheese("feta", 0.0, 1500));

   double removed = reduce_weight(cheese, 0.5);
    write_line("Removed: " + to_string(removed));
    print_cheese(cheese);

    removed = reduce_weight(cheese, 1.7);
    write_line("Removed: " + to_string(removed));
    print_cheese(cheese);

    removed = reduce_weight(cheese, -2.0);
    write_line("Removed: " + to_string(removed));
    increase_weight(cheese, -1.0);
    print_cheese(cheese);

    increase_weight(cheese, 2.5);
    print_cheese(cheese);

    for (int i = 0; i < shop.cheeses.length(); i++)
    {
    write_line(cheese_to_string(shop.cheeses[i], true));
    }

    add_cheese(shop, new_cheese("cheddar", 1.5, 2000));

    print_stock_list(shop);
    handle_add_cheese(shop);
    print_stock_list(shop);