#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iomanip>
#include "../menuItem/menuItem.h"



#define STARTSIZEORDER 5
/*!
 * This is the Customer class. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting customer first name, last name, the loyalty number
 * the number of loyalty points associated with a customer and the number of items in their current order
 * and an array of MenuItem that a customer has added to their order (max size 50)
*/
class Customer{
    string customerFirst, customerLast; 
    long int loyaltyNumber;
    long int numberLoyaltyPoints; 
    //int numItemsInOrder; 
    DynamicArray<MenuItem*> currentOrder;
    long int currentArrayMax;

    public:

        Customer();
        Customer(const string, const string, const long int, const long int);
        Customer(const Customer&);
        ~Customer();
        
        void setCustomerFirst(const string);
        string getCustomerLast() const;
        void setCustomerLast(const string);
        long int getLoyaltyNumber() const;
        void setLoyaltyNumber(const long int);
        long int getNumberLoyaltyPoints() const;
        void setNumberLoyaltyPoints(const long int);
        DynamicArray<MenuItem*> getCurrentOrder() const;
        void addItemToOrder( MenuItem*);
        //int getNumItemsInOrder() const;
        //void setNumItemsInOrder(const int);
        float calculateCost() const;
        //virtual void displayOrder()const;
        void displayCustomerInformation() const;
        string getCustomerFirst() const;
        void clearOrder();

        friend ostream& operator<<(ostream&, Customer*); //added
};
#endif