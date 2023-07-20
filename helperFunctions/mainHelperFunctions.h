#ifndef MAINHELPERFUNCTIONS_H
#define MAINHELPERFUNCTIONS_H

#include "../customer/customer.h"
#include "../drink/drink.h"
#include "../food/food.h"
#include <fstream>
#define STARTING_NUM_CUSTOMERS 10

//display functions
void displayPointRedemptionMenu();
void displayLoyaltyInformationPrompt();
void displayMemberJoin();
void displayMenuItems();

//loyalty functions
int runLoyaltyProgram(DynamicArray<Customer*>& arr);
void overwriteLoyaltyDatabase(DynamicArray<Customer*>& arr);
const bool pointSystemPrompt(const Customer&);
void getLoyaltyDatabase(DynamicArray<Customer*>&);
int getNumberOfPointsToRedeem(string&, int);
void useLoyalty(Customer&, int);

//customer functions
const DynamicArray<MenuItem*> placeOrder();
Customer* createCustomer();


//user interactions
template <typename T>
T getUserEntry();
MenuItem& addItemToOrder(int);
const void calculateChange(const Customer&);

//food
void promptFoodAddons(Food&);
void selectIngredient(Food&);

//drink
void promptDrinkExtras(Drink&);


#endif
