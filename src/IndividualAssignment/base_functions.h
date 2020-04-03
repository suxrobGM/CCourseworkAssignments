#ifndef BASE_FUNCTIONS_H_INCLUDED
#define BASE_FUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Displays just welcome message
void display_welcome_message(const char* program_desc)
{
    puts("-----------------------------------------------------------------------");
    puts("\t\tWelcome to the program! :)");
    puts(program_desc);
    puts("-----------------------------------------------------------------------");
}

// Base functions to display run and quit actions in console output
void display_choice_action()
{
    puts("\nWhat action do you wish to perform?");
    puts("\nType \"run\" to start or \"quit\" to exit program");
}

// Function used for displaying user friendly errors
void display_error_message(const char* msg)
{
    puts("\n-----------------------------------------------------------------------");
    printf("ERROR: %s\n", msg);
    puts("-----------------------------------------------------------------------\n");
}

// Function used for close terminal process
void quit_program()
{
    puts("\n-----------------------------------------------------------------------");
    puts("Quitted program!");
    puts("-----------------------------------------------------------------------\n");
    exit(0);
}

// Check that string does not contain numbers and other symbols
bool is_valid_name(const char* str)
{
    bool is_valid = true;
    int str_length = strlen(str);

    for (size_t i = 0; i < str_length; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        
        if (!isalpha(str[i]))
        {
            is_valid = false;
            break;
        }
    }
    
    return is_valid;
}

#endif // BASE_FUNCTIONS_H_INCLUDED