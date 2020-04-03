#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) Vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_SIZE(vec) vector_size(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct Vector {
    void** items;
    int capacity;
    int size;
} Vector;

void vector_init(Vector*);
int vector_size(Vector*);
static void vector_resize(Vector*, int);
void vector_add(Vector*, void*);
void vector_set(Vector*, int, void*);
void* vector_get(Vector*, int);
void vector_delete(Vector*, int);
void vector_free(Vector*);

void vector_init(Vector* v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->size = 0;
    v->items = (void**)malloc(sizeof(void*) * v->capacity);
}

int vector_size(Vector* v)
{
    return v->size;
}

static void vector_resize(Vector* v, int capacity)
{
    #ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
    #endif

    void** items = (void**)realloc(v->items, sizeof(void*) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(Vector* v, void* item)
{
    if (v->capacity == v->size)
    {
        vector_resize(v, v->capacity * 2);
    }
        
    //void* copied_item = malloc(sizeof(item));
    //memcpy(copied_item, item, sizeof(item));   
    v->items[v->size++] = item;
}

void vector_set(Vector* v, int index, void* item)
{
    if (index >= 0 && index < v->size)
        v->items[index] = item;
}

void* vector_get(Vector* v, int index)
{
    if (index >= 0 && index < v->size)
        return v->items[index];
    return NULL;
}

void vector_delete(Vector* v, int index)
{
    if (index < 0 || index >= v->size)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->size - 1; i++) 
    {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->size--;

    if (v->size > 0 && v->size == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(Vector* v)
{
    free(v->items);
}

#endif