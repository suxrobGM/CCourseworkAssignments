/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#include "base_functions.h"
#define BUFFER_SIZE 128

void remove_spaces(char* str)
{
    char* cpy = str;  // an alias to iterate through str without moving str
    char* temp = str;

    while (*cpy)
    {
        if (*cpy != ' ')
            *temp++ = *cpy;
        cpy++;
    }
    *temp = 0;
}

// properly declared for compatibility with qsort 
int cmp_str(const void *lhs, const void *rhs)
{
    return strcmp(lhs, rhs);
}

// Check that two given strings are anagram or not. Algorithm complexity is O(nLogn)
bool check_anagram(const char* str1, const char* str2)
{
    // Get lengths of both strings 
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* s1 = malloc(sizeof(char)*len1);
    char* s2 = malloc(sizeof(char)*len1);
    strcpy(s1, str1);
    strcpy(s2, str2);

    // remove any other spaces
    remove_spaces(s1);
    remove_spaces(s2);

    // reassigning after removed whitespaces
    len1 = strlen(s1);
    len2 = strlen(s2);

    // If length of both strings is not same, then they 
    // cannot be anagram
    if (len1 != len2)
    {
        return false;
    }

    // Sort both the strings 
    qsort(s1, len1, sizeof(str1[0]), cmp_str);
    qsort(s2, len2, sizeof(str2[0]), cmp_str);

    // Compare sorted strings 
    for (size_t i = 0; i < len1; i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    free(s1);
    free(s2);
    
    return true;
}


void run_program()
{
    puts("Function: whether two given strings are anagram");
    puts("Example: pears and spare, stone and tones");
    puts("-----------------------------------------------------------------------\n");

    char str1[BUFFER_SIZE], str2[BUFFER_SIZE];

    INPUT_FIRST_STR_AGAIN: printf("Input the first string: ");
    fflush(stdin);
    gets(str1);

    if (!is_valid_name(str1))
    {
        display_error_message("Words do not contain any other characters or numbers, please try again");
        goto INPUT_FIRST_STR_AGAIN;
    }
    
    INPUT_SECOND_STR_AGAIN: printf("Input the second string: ");
    fflush(stdin);
    gets(str2);

    if (!is_valid_name(str2))
    {
        display_error_message("Words do not contain any other characters or numbers, please try again");
        goto INPUT_SECOND_STR_AGAIN;
    }

    if (check_anagram(str1, str2))
    {
        printf("%s and %s are Anagram\n", str1, str2);
    }
    else
    {
        printf("%s and %s are not Anagram\n", str1, str2);
    }
}

// Driver code
int main()
{
    display_welcome_message("This program will check whether two given strings are an anagram or not");
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