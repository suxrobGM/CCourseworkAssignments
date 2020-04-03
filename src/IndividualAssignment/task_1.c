#include "base_functions.h"
#include "order.h"
#include "vector.h"

#define ORDERS_SIZE 16
#define BUFFER_SIZE 128

/**
 * Global variables
 * */
Vector orders;
//Order current_order;
char customer_name[BUFFER_SIZE];
char customer_IC[BUFFER_SIZE];
bool is_continue_ordering;

void input_name_IC() 
{
    INPUT_NAME_AGAIN: printf("Please enter your name: ");

    fflush(stdin);
    gets(customer_name);

    if (!is_valid_name(customer_name))
    {
        display_error_message("Invalid customer name, there should be only alphabetic symbols, please try again");
        goto INPUT_NAME_AGAIN;
    }

    printf("Please enter your IC / Passport number: ");

    fflush(stdin);
    scanf("%s", &customer_IC);
}

void show_menu()
{
    puts("\n-----------------------------------------------------------------------");
    puts("\t\t\t ORDER");
    puts("\t\t\t---------\n");
        
    if (!is_continue_ordering) 
    {
        input_name_IC();
    }

    puts("-----------------------------------------------------------------------");
    puts("Here is our menu, please have a look: \n");
    puts(" (1) Acer - RM 1700.00 (5.0% Discount)");
    puts(" (2) HP - RM 2500.00");
    puts(" (3) Dell - RM 2450.00 (5.0% Discount)");
    puts(" (4) Lenovo - RM 1800.00 (10.0% Discount)");
    puts(" (5) Toshiba - RM 1500.00");
    puts(" (6) Sony - RM 2200.00 (5.0% Discount)");
    puts(" (7) Checkout");
    puts("-----------------------------------------------------------------------");
}

void show_item(Order current_order)
{
    puts("-----------------------------------------------------------------------");
    puts("\t\t\t ITEM:");
    puts("\t\t\t---------");
    printf("Order: %s\n", current_order.name);
    printf("Price: RM %0.2f\n", current_order.price);
    puts("Current quantity: 0");
    puts("-----------------------------------------------------------------------");

    INPUT_DISTANCE_AGAIN: puts("Please enter the quantity: ");

    fflush(stdin);
    int input_return_value = scanf("%d", &current_order.quantity);

    if (input_return_value != 1)
    {
        display_error_message("Invalid value, the input is NOT INTEGER value, please try again");
        goto INPUT_DISTANCE_AGAIN;
    }
    
    // TODO 
    Order* copied_order = (Order*)malloc(sizeof(Order));
    copy_order(copied_order, &current_order);
    vector_add(&orders, copied_order);
}

void show_subtotal()
{
    puts("-----------------------------------------------------------------------");
    puts("\t\t\t SUBTOTAL:");
    puts("\t\t\t---------");
    puts("Order:");

    float subtotal = 0.0f;
    for (size_t i = 0; i < vector_size(&orders); i++)
    {
        #define order ((Order*)vector_get(&orders, i)) // name alias
            
        if (order->discount > 0) 
        {
            printf("%s : %d * RM %.2f - %.2f%% = RM %.2f\n", order->name, order->quantity, order->price, order->discount, get_subtotal(order));    
        } 
        else {
            printf("%s : %d * RM %.2f = RM %.2f\n", order->name, order->quantity, order->price, get_subtotal(order));
        }
            
        subtotal += get_subtotal(order);
    }
        
    printf("Subtotal: RM %.2f\n\n", subtotal);
    printf("-----------------------------------------------------------------------\n\n");

    printf("Would you like to continue ordering?\n");
    INPUT_CHOOSE_ACTION_AGAIN: printf("Enter \"y\" to add more items or \"n\" to checkout\n");

    char user_select[4];
    fflush(stdin);
    scanf("%s", user_select);

    if (strcmp(user_select, "y") == 0) 
    {
        is_continue_ordering = true;
        printf("%d", is_continue_ordering);
    } 
    else if (strcmp(user_select, "n") == 0) 
    {
        is_continue_ordering = false;
    }
    else {
        display_error_message("Invalid value, please enter either \'y\' or \'n\'");
        goto INPUT_CHOOSE_ACTION_AGAIN;
    }
    
}

void show_receipt()
{
    puts("\n-----------------------------------------------------------------------");
    puts("\t\t\t RECEIPT");
    puts("\t\t\t---------\n");
    puts("Thank you for purchasing laptop at this shop!\n");
    printf("Name:\t%s\n", customer_name);
    printf("IC / Passport: %s\n", customer_IC);
    puts("\nOrder:\n");
        
    float subtotal = 0.0f;

    for (size_t i = 0; i < vector_size(&orders); i++)
    {
        #define order ((Order*)vector_get(&orders, i)) // name alias
            
        if (order->discount > 0) 
        {
            printf("%s : %d * RM %.2f - %.2f%% = RM %.2f\n", order->name, order->quantity, order->price, order->discount, get_subtotal(order));    
        } 
        else {
            printf("%s : %d * RM %.2f = RM %.2f\n", order->name, order->quantity, order->price, get_subtotal(order));
        }
            
        subtotal += get_subtotal(order);
    }

    float sst = subtotal * 0.02f;
    float grand_total = subtotal + sst;

    printf("\nSubtotal: RM %.2f\n", subtotal);
    printf("SST: RM %.2f\n", sst);
    printf("Grand Total: RM %.2f\n", grand_total);
    puts("\n\t\tPlease enjoy your laptop!");
    puts("-----------------------------------------------------------------------\n");
}

void run_program() 
{
    char choosed_action[8];

    while (1) 
    {
        if (!is_continue_ordering) 
        {
            display_welcome_message("This program will calculate total prices in the laptop shop");
            puts("What would you like to do?");
            puts("Type \"start\" to begin shopping or \"quit\" to exit program");

            fflush(stdin);
            scanf("%s", &choosed_action);
        }
        else {
            strcpy(choosed_action, "start");
        }

        if (strcmp(choosed_action, "start") == 0) 
        {
            show_menu();

            puts("What would you like to order?");
            INPUT_ORDER_NUMBER_AGAIN: puts("Place order by entering the number next to the laptop: ");

            int menu_choice;
            //Order current_order;
            fflush(stdin);
            int input_return_value = scanf("%d", &menu_choice);

            if (input_return_value != 1)
            {
                display_error_message("Invalid value, the input is NOT INTEGER value, please try again");
                goto INPUT_ORDER_NUMBER_AGAIN;
            }
            else if (menu_choice <= 0 || menu_choice > 7)
            {
                display_error_message("Invalid value, please enter numbers between 1 and 7");
                goto INPUT_ORDER_NUMBER_AGAIN;
            }

            switch (menu_choice) 
            {
                case 1: 
                {
                    Order current_order = create_order("Acer", 1700.0f, 5.0f, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 2: 
                {
                    Order current_order = create_order("HP", 2500.0f, 0, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 3: 
                {
                    Order current_order = create_order("Dell", 2450.0f, 5.0f, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 4: 
                {
                    Order current_order = create_order("Lenovo", 1800.0f, 10.0f, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 5: 
                {
                    Order current_order = create_order("Toshiba", 1500.0f, 0, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 6: 
                {
                    Order current_order = create_order("Sony", 2200.0f, 5.0f, 1);
                    show_item(current_order);
                    show_subtotal();

                    if (!is_continue_ordering) 
                    {
                        show_receipt();
                    }
                    break;
                }
                case 7: 
                {
                    is_continue_ordering = false;
                    show_receipt();
                    break;
                }    
                default: 
                {
                    puts("\n-----------------------------------------------------------------------");
                    puts("ERROR: Invalid value, please try again");
                    puts("-----------------------------------------------------------------------\n");
                }
            }
        }
        else if (strcmp(choosed_action, "quit") == 0) 
        {
            vector_free(&orders);
            quit_program();
            return;
        }
        else {
            puts("\n-----------------------------------------------------------------------");
            puts("ERROR: Invalid value, please try again");
            puts("-----------------------------------------------------------------------\n");               
        }
    }   
}

int main() 
{
    vector_init(&orders);
    run_program();
    vector_free(&orders);

    return 0;
}