/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#ifndef ORDER_H
#define ORDER_H

typedef struct Order {
    char* name;
    float price;
    float discount;
    int quantity;

} Order;

Order order_create(char* name, float price, float discount, int quantity)
{
    Order order;
    order.name = name;
    order.price = price;
    order.discount = discount;
    order.quantity = quantity;
    return order;
}

void order_copy(Order* destination, Order* source)
{
    destination->name = source->name;
    destination->discount = source->discount;
    destination->price = source->price;
    destination->quantity = source->quantity;
}

float get_subtotal(const Order* order) 
{
    return order->price * order->quantity * ((100.0f - order->discount) / 100.0f);
}

#endif