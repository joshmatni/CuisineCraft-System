#ifndef MENUITEM_H
#define MENUITEM_H

#include "../dynamicArray/dynamicArray.cpp"
#define MAX_NUMBER_INGREDIENTS 10

class MenuItem{
    protected:
        float cost;
        string itemName; 
        int pointWorth;
        virtual ostream& displayItemInformation(ostream&) const;

    public:
        MenuItem();
        MenuItem(const string, const int);
        MenuItem(const MenuItem&);
        virtual ~MenuItem(){};
    
        
        float getCost()const;
        void setCost(const float);
        string getItemName()const;
        void setItemName(const string);
        int getPointWorth()const;
        void setPointWorth(const int);
        //virtual void displayNameAndCost() const;

        //new
        virtual void calculateMenuItemCost() = 0;
        //virtual void displayItemInformation() const;

        float operator + (float); //added 
        friend ostream& operator<<(ostream&, const MenuItem&); //added
};
#endif