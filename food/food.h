#ifndef FOOD_H
#define FOOD_H

#include "../menuItem/menuItem.h"
#define LOYALTYFILE "../main/loyalty.txt"
class Food : public MenuItem{
    DynamicArray<string> ingredients;
    int numberIngredients; 
    int currentMaxNumberIngredients;
    DynamicArray<string> availableExtras;
    int numAvailableExtras;
    public: 
        Food();
        Food(const DynamicArray<string>, const int, const string, const int);
        Food(const Food&);
        ~Food()override;

        DynamicArray<string> getIngredients();
        void addIngredient(const string);
        int getNumberIngredients()const;
        void setAvailableExtras();
        DynamicArray<string> getAvailableExtras();
        int getNumAvailableExtras()const;

        void calculateMenuItemCost() override;
        ostream& displayItemInformation(ostream&) const override;
};
#endif