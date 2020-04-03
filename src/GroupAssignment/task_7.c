#include "base_functions.h"
#include <string.h>


void run_program()
{
    puts("Please enter 10 integers");
    int number = 0;
    int sum = 0;
    int input_return_value = 0;
    float average = 0.0f;

    for (size_t i = 1; i <= 10; i++)
    {
        INPUT_AGAIN: printf("Number %d: ", i); // works if input is not int value
        input_return_value = scanf("%d", &number);

        if (input_return_value != 1)
        {
            display_error_message("Invalid value, the input is NOT integer value, please try again");
            fflush(stdin);
            goto INPUT_AGAIN;
        }
        
        sum += number;
    }

    average = (float)sum / 10.0f;
    
    puts("-----------------------------------------------------------------------");
    printf("Sum: %d\n", sum);
    printf("Average: %0.1f\n", average);
    puts("-----------------------------------------------------------------------");
}

int main()
{
    display_welcome_message("This program will calculate total and average of 10 integer numbers");
    char choosed_action[10];

    while (1)
    {
        display_choice_action();
        fflush(stdin); // clear input buffer
        scanf("%s", choosed_action);

        if (strcmp(choosed_action, "run") == 0)
        {
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