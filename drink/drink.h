#ifndef DRINK_H
#define DRINK_H
#include "../menuItem/menuItem.h"

class Drink : public MenuItem{
    int size; 
    bool needsStraw;
    bool needsIce; 

    public:
        Drink();
        Drink(const int, const bool, const bool, const string, const int);
        Drink(const Drink&);

        int getSize()const;
        void setSize(const int);
        bool getNeedsStraw()const;
        void setNeedsStraw(const bool);
        bool getNeedsIce()const;
        void setNeedsIce(const bool);
        
        void calculateMenuItemCost() override;
        ostream& displayItemInformation(ostream&) const override;
};
#endif