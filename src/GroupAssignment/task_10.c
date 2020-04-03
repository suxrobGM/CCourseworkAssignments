/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#include "base_functions.h" // frequently used functions
#include <string.h>

double max_value_array(double array[], int arr_size)
{
    double max_value = array[0];

    for (size_t i = 0; i < arr_size; i++)
    {
        if (max_value < array[i])
        {
            max_value = array[i];
        }
    } 

    return max_value;
}

double min_value_array(double array[], int arr_size)
{
    double min_value = array[0];

    for (size_t i = 0; i < arr_size; i++)
    {
        if (min_value > array[i])
        {
            min_value = array[i];
        }
    } 

    return min_value;
}

void run_program()
{
    int arr_length = 1;
    int input_return_value = 0;
    double number = 0;

    INPUT_ARR_SIZE_AGAIN: printf("Please enter size of array: ");
    fflush(stdin);
    input_return_value = scanf("%d", &arr_length);

    if (input_return_value != 1)
    {
        display_error_message("Invalid value, the input is NOT integer value, please try again");
        goto INPUT_ARR_SIZE_AGAIN; // used goto operator
    }

    double* arr = (double*)malloc(arr_length * sizeof(double));
    printf("Input %d number of elements in the array\n", arr_length);

    for (size_t i = 0; i < arr_length; i++)
    {
        INPUT_AGAIN: printf("Element %d : ", i); // if wrong again work this part of code
        input_return_value = scanf("%lf", &number);

        if (input_return_value != 1)
        {
            display_error_message("Invalid value, the input is NOT numeric value, please try again");
            fflush(stdin);
            goto INPUT_AGAIN;
        }

        arr[i] = number;
        //printf("NUMBER VALUE: %f\n", number);
        //printf("ARR VALUE: %f\n", arr[i]);
    }

    double max_vlaue = max_value_array(arr, arr_length);
    double min_vlaue = min_value_array(arr, arr_length);
    free(arr);

    puts("-----------------------------------------------------------------------");
    printf("Maximum value: %0.2f\n", max_vlaue);
    printf("Minimum value: %0.2f\n", min_vlaue);
    puts("-----------------------------------------------------------------------");
}

int main()
{
    display_welcome_message("This program will find the maximum and minimum value in a array");
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