#ifndef ORDER_H
#define ORDER_H

typedef struct Order {
    char* name;
    float price;
    float discount;
    int quantity;

} Order;

Order create_order(char* name, float price, float discount, int quantity)
{
    Order order;
    order.name = name;
    order.price = price;
    order.discount = discount;
    order.quantity = quantity;
    return order;
}

void copy_order(Order* destination, Order* source)
{
    //destination = (Order*)malloc(sizeof(Order));
    strcpy(destination->name, source->name);
    destination->discount = source->discount;
    destination->price = source->price;
    destination->quantity = source->quantity;
}

float get_subtotal(const Order* order) 
{
    return order->price * order->quantity * ((100.0f - order->discount) / 100.0f);
}

#endif