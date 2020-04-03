/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#include "base_functions.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char staff_name[128]; // gloabal string variable it used for storing staff name
bool is_first_run = true; // evaluate that program run or not

void display_rates()
{
    puts("The Petrol allowance claim rate is shown in the table below");
    puts("\n-----------------------------------------------------------------------");
    puts("\tKilometer\t\t\tRates");
    puts("\tFirst 10 Km\t\t\tRM 0.50 per km");
    puts("\tNext 50 Km (from 11 to 60)\tRM 0.80 per km");
    puts("\tNext 50 Km (from 61 to 110)\tRM 1.00 per km");
    puts("\tNext 50 Km (from 111 to 160)\tRM 1.30 per km");
    puts("\tBeyond 160 Km\t\t\tRM 1.50 per km");
    puts("-----------------------------------------------------------------------\n");
    puts("If the total allowance is morethan RM100.00 than an additional bonus of 5% is added as their incentive amount with total amount\n");
}

// check that staff name does not contain numbers and other symbols
bool is_valid_name(const char* staff_name)
{
    bool is_valid = true;
    int str_length = strlen(staff_name);

    for (size_t i = 0; i < str_length; i++)
    {
        if (staff_name[i] == ' ')
        {
            continue;
        }
        
        if (!isalpha(staff_name[i]))
        {
            is_valid = false;
            break;
        }
    }
    
    return is_valid;
}

void run_program()
{
    //char staf_name[128];

    if (is_first_run) // if wrong again work this part of code
    {
        INPUT_NAME_AGAIN: printf("Enter staff name: ");
        fflush(stdin);
        gets(staff_name);
        
        if (!is_valid_name(staff_name))
        {
            display_error_message("Invalid staff name, there should be only alphabetic symbols, please try again");
            goto INPUT_NAME_AGAIN;
        }

        is_first_run = false;
    }
    
    
    int input_return_value = 0;
    float distance = 0;
    INPUT_DISTANCE_AGAIN: printf("Enter distance travelled in kilometers: "); // if wrong again work this part of code
    fflush(stdin);
    input_return_value = scanf("%f", &distance);

    if (input_return_value != 1)
    {
        display_error_message("Invalid value, the input is NOT NUMERIC value, please try again");
        goto INPUT_DISTANCE_AGAIN;
    }
    
    puts("\n-----------------------------------------------------------------------\n");
    puts("Final Receipt:\n");
    printf("Name: %s\n", staff_name);
    printf("Distance traveled: %0.1fkm\n\n", distance);

    float total_price = 0.0f;
    float this_distance_price = 0.0f;
    float rest_distance = distance;
    bool distance_finished = false;

    // First distance
    if (rest_distance >= 10.0f)
    {
        this_distance_price = 10.0f * 0.5f;
        total_price += this_distance_price;
        rest_distance -= 10.0f;
        printf("First 10 km: 10.0km * RM 0.50 = RM %.2f\n", this_distance_price);
    }
    else if (rest_distance > 0 && rest_distance < 10.0f)
    {
        this_distance_price = rest_distance * 0.5f;
        total_price += this_distance_price;
        printf("*First 10 km: %0.1fkm * RM 0.50 = RM %.2f\n", rest_distance, this_distance_price);
        distance_finished = true;
    }
    
    // Second distance
    if (rest_distance >= 50.0f)
    {
        this_distance_price = 50.0f * 0.8f;
        total_price += this_distance_price;
        rest_distance -= 50.0f;
        printf("Next 50 km: 50.0km * RM 0.80 = RM %.2f\n", this_distance_price);
    }
    else if (!distance_finished && rest_distance > 10 && rest_distance < 50)
    {
        this_distance_price = rest_distance * 0.8f;
        total_price += this_distance_price;
        printf("*Next 50 km: %0.1fkm * RM 0.80 = RM %.2f\n", rest_distance, this_distance_price);
        distance_finished = true;
    }

    // Third distance
    if (rest_distance >= 50.0f)
    {
        this_distance_price = 50.0f * 1.0f;
        total_price += this_distance_price;
        rest_distance -= 50.0f;
        printf("Next 50 km: 50.0km * RM 1.00 = RM %.2f\n", this_distance_price);
    }
    else if (!distance_finished && rest_distance > 0 && rest_distance < 50)
    {
        this_distance_price = rest_distance * 1.0f;
        total_price += this_distance_price;
        printf("*Next 50 km: %0.1fkm * RM 1.00 = RM %.2f\n", rest_distance, this_distance_price);
        distance_finished = true;
    }

    // Fourth distance
    if (rest_distance >= 50.0f)
    {
        this_distance_price = 50.0f * 1.30f;
        total_price += this_distance_price;
        rest_distance -= 50.0f;
        printf("Next 50 km: 50.0km * RM 1.30 = RM %.2f\n", this_distance_price);
    }
    else if (!distance_finished && rest_distance > 0 && rest_distance < 50)
    {
        this_distance_price = rest_distance * 1.30f;
        total_price += this_distance_price;
        printf("*Next 50 km: %0.1fkm * RM 1.30 = RM %.2f\n", rest_distance, this_distance_price);
        distance_finished = true;
    }

    // Fifth distance
    if (!distance_finished && rest_distance > 0)
    {
        this_distance_price = rest_distance * 1.50f;
        total_price += this_distance_price;
        printf("Beyond 100 km: %0.1fkm * RM 1.50 = RM %.2f\n", rest_distance, this_distance_price);
    }
    
    if (total_price > 100.0f)
    {
        printf("Allowance: RM %0.2f + 5%% = RM %.2f\n", total_price, total_price * 1.05f);
    }
    else
    {
        printf("Allowance: RM %0.2f\n", total_price);
    }
}

int main()
{
    display_welcome_message("This program will calculate Petrol allowance");
    char choosed_action[10];

    while (1)
    {
        display_choice_action();
        fflush(stdin);
        scanf("%s", choosed_action);

        if (strcmp(choosed_action, "run") == 0)
        {
            display_rates();
            run_program();
        }
        else if (strcmp(choosed_action, "quit") == 0)
        { 
            quit_program();
            break;
        }
        else
        {
            display_error_message("Invalid value, please try again");
        }
    }

    return 0;
}