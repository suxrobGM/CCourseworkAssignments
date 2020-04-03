#include "base_functions.h"
#include <string.h>

void run_program()
{
    puts("Please enter 10 even numbers");
    int number = 0;
    int sum = 0;
    int input_return_value = 0;

    for (size_t i = 1; i <= 10; i++)
    {
        INPUT_AGAIN: printf("Even number %d: ", i); // if wrong again work this part of code
        input_return_value = scanf("%d", &number);

        if (number % 2 != 0)
        {
            display_error_message("Invalid value, the input is NOT EVEN integer value, please try again");
            fflush(stdin);
            goto INPUT_AGAIN;
        }

        if (input_return_value != 1)
        {
            display_error_message("Invalid value, the input is NOT integer value, please try again");
            fflush(stdin);
            goto INPUT_AGAIN;
        }
        
        sum += number;
    }
    
    puts("-----------------------------------------------------------------------");
    printf("Sum: %d\n", sum);
    puts("-----------------------------------------------------------------------");
}

int main()
{
    display_welcome_message("This program will calculate total of 10 even integer numbers");
    char choosed_action[10];

    while (1)
    {
        display_choice_action();
        fflush(stdin);
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