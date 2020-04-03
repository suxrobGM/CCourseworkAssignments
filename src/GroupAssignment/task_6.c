#include <stdio.h>

void subtask_1()
{
    printf("Subtask 1\n");
    int i;
    for(i = 0; i < 10; i = i + 2) {
        printf("%d\n", i);
    }
}

void subtask_2()
{
    printf("Subtask 2\n");
    int i;
    for(i = 100; i >= 0; i = i - 7) 
    {
        printf("%d\n", i); 
    }
}

void subtask_3()
{
    printf("Subtask 3\n");
    int i;
    for(i = 1; i <= 10; i = i + 1) 
    {
	    printf("%d\n", i); 
    }
}

void subtask_4()
{
    printf("Subtask 4\n");
    int i;
    for(i = 2; i < 100; i = i * 2) 
    {
        printf("%d\n", i); 
    }
}

void subtask_5()
{
    printf("Subtask 5\n");
    int i;
    for(i = 10; i < 350; i = i + 45) 
    {
        printf("%d\n", i);
    }
}

int main()
{
    subtask_1();
    subtask_2();
    subtask_3();
    subtask_4();
    subtask_5();    

    return 0;
}