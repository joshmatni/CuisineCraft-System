#include "customer.h"
Customer::Customer(){
    customerFirst = "Jane";
    customerLast = "Doe";
    loyaltyNumber = 0;
    numberLoyaltyPoints = 1111111;
    //numItemsInOrder = 0;
    currentArrayMax = STARTSIZEORDER;
}
Customer::Customer(const string first, const string last, const long int id, const long int numPts){
    customerFirst = first;
    customerLast = last;
    loyaltyNumber = id;
    numberLoyaltyPoints = numPts;
    //numItemsInOrder = 0;
    currentArrayMax = STARTSIZEORDER;
}
Customer::Customer(const Customer& rhs){
    customerFirst = rhs.customerFirst;
    customerLast = rhs.customerLast;
    loyaltyNumber = rhs.loyaltyNumber;
    numberLoyaltyPoints = rhs.numberLoyaltyPoints;
    //numItemsInOrder = rhs.numItemsInOrder;
    currentArrayMax = STARTSIZEORDER;
    for(int i = 0; i < currentOrder.getCurrentNumElementsStored(); i++){
        currentOrder.addElementToEndOfArr(rhs.currentOrder.getElementAtIndex(i));
    }
}
Customer::~Customer(){
    /*for(int i = 0; i < currentArrayMax; i++){
        delete currentOrder[i];
    }
    delete [] currentOrder;*/
}

string Customer::getCustomerFirst() const{
    return customerFirst;
}
void Customer::setCustomerFirst(const string name){
    customerLast = name;
}

string Customer::getCustomerLast()const{
    return customerLast;
}
void Customer::setCustomerLast(const string name){
    customerLast = name;
}


long int Customer::getLoyaltyNumber()const{
    return loyaltyNumber;
}
void Customer::setLoyaltyNumber(const long int id){
    loyaltyNumber = id;
}   

long int Customer::getNumberLoyaltyPoints()const{
    return numberLoyaltyPoints;
}
void Customer::setNumberLoyaltyPoints(const long int numPts){
    numberLoyaltyPoints = numPts;
}


DynamicArray<MenuItem*> Customer::getCurrentOrder()const{
    return currentOrder;
}
void Customer::addItemToOrder(MenuItem* newItem){
    currentOrder.addElementToEndOfArr(newItem);
}

// int Customer::getNumItemsInOrder()const{
//     return numItemsInOrder;
// }

float Customer::calculateCost() const{
    float customerTotal = 0;
    float currentTaxRate = 1.0827;
    float tempZero = 0.00;
    for(int i = 0; i < currentOrder.getCurrentNumElementsStored(); i++){
        float tempCost = *currentOrder.getElementAtIndex(i) + tempZero;
        customerTotal += tempCost;
    }
    customerTotal *= currentTaxRate;
    return customerTotal;
}
// void Customer::displayOrder()const{
//     cout <<endl << "=====Your Order=====" << endl;
    
//     for(int i = 0; i < currentOrder.getCurrentNumElementsStored(); i++){
//         cout << currentOrder.getElementAtIndex(i); //changed
//     }
//     cout << "Your Total Today Is: $" << std::fixed << setprecision(2) << calculateCost()<< endl << endl;

// }

void Customer::displayCustomerInformation()const{
    cout <<endl << "Welcome " <<getCustomerFirst() <<" " << getCustomerLast() << "!" << endl;
    cout << "You have " << getNumberLoyaltyPoints() << " Loyalty Points." << endl;
}

// void Customer::setNumItemsInOrder(const int numItem){
//     numItemsInOrder = numItem;
// }

void Customer::clearOrder(){
    currentOrder.clearArray();
}

ostream& operator<<(ostream& outStream, Customer* customer)
{
    outStream <<endl << "=====Your Order=====" << endl;
    
    for(int i = 0; i < customer->getCurrentOrder().getCurrentNumElementsStored(); i++){
        outStream << *(customer->getCurrentOrder().getElementAtIndex(i)); //changed
    }
    outStream << "Your Total Today Is: $" << std::fixed << setprecision(2) << customer->calculateCost()<< endl << endl;
    return outStream;
}


