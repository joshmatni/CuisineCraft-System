#include "drink.h"

Drink::Drink():MenuItem(){
    size = 0;
    needsIce = false;
    needsStraw = false;
    cost = 0;
    itemName = "Fountain Drink";
    pointWorth = 50;
}
Drink::Drink(const int sz, const bool ice,const bool straw, string nm, const int pts):MenuItem(nm, pts){
    size = sz;
    needsIce = ice;
    needsStraw = straw;
    calculateMenuItemCost();
    itemName = nm;
}
Drink::Drink(const Drink& rhs):MenuItem(rhs){
    size = rhs.size;
    needsIce = rhs.needsIce;
    needsStraw = rhs.needsStraw;
    cost = rhs.cost;
}

int Drink::getSize()const{
    return size;
}
void Drink::setSize(const int sz){
    size = sz;
}

bool Drink::getNeedsStraw()const{
    return needsStraw; 
}
void Drink::setNeedsStraw(const bool straw){
    needsStraw = straw;
}

bool Drink::getNeedsIce()const{
    return needsIce;
}
void Drink::setNeedsIce(const bool ice){
    needsIce = ice;
}
void Drink::calculateMenuItemCost(){
    if(size == 16){
        cost = 2.99;
    }
    else if(size == 20){
        cost = 3.25;
    }
    else if(size == 32){
        cost = 3.75;
    }
    if(needsIce){
        cost += .25;
    }
    if(needsStraw){
        cost += .50;
    }
}

ostream& Drink::displayItemInformation(ostream& outStream) const{
    //displayNameAndCost();
    MenuItem::displayItemInformation(outStream);
    if (needsIce || needsStraw){
        outStream << "INCLUDE: ";
        if(needsIce){
            outStream << "Ice";
        }   
        if (needsIce && needsStraw){
            outStream << ", Straw";
        }
        else if(needsStraw){
            outStream << "Straw";
        }
        outStream << endl <<endl;
        
    } 
    return outStream;
}