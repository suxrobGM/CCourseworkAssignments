/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#include "vector.h"

typedef struct Person 
{
    char* first_name;
    char* last_name;
    int age;
} Person;

Person create_person(char* first_name, char* last_name, int age)
{
    Person p;
    p.first_name = first_name;
    p.last_name = last_name;
    p.age = age;
    return p;
}

Vector vec;
Person p1;

int main()
{
    p1 = create_person("Thomas", "Jefferson", 25);

    vector_init(&vec);
    vector_add(&vec, &p1);
    Person p2 = create_person("John", "Adams", 21);
    vector_add(&vec, &p2);
    Person p3 = create_person("Sukhrob", "Ilyosbekov", 21);
    vector_add(&vec, &p3);
    //vector_add(&vec, (void*)"s4");

    for (size_t i = 0; i < vector_size(&vec); i++)
    {
        Person* p = (Person*)vector_get(&vec, i);
        printf("%s %s %d\n", p->first_name, p->last_name, p->age);
    }
    vector_free(&vec);

    return 0;
}