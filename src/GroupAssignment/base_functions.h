#ifndef BASE_FUNCTIONS_H_INCLUDED
#define BASE_FUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

// just welcome message
void display_welcome_message(const char* program_desc)
{
    puts("-----------------------------------------------------------------------");
    puts("\t\tWelcome to the program! :)");
    puts(program_desc);
    puts("-----------------------------------------------------------------------");
}

void display_choice_action()
{
    puts("\nWhat action do you wish to perform?");
    puts("\nType \"run\" to begin calculation or \"quit\" to exit program");
}

// function used for displaying user friendly errors
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

#endif // BASE_FUNCTIONS_H_INCLUDED