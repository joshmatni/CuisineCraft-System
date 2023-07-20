#include "menuItem.h"

MenuItem::MenuItem(){
    itemName = "NONE";
    cost = -1;
    pointWorth = 0;
}
MenuItem::MenuItem(const MenuItem& rhs){
    itemName = rhs.itemName;
    cost = rhs.cost;
    pointWorth = rhs.pointWorth;
}
MenuItem::MenuItem(const string name, const int pts){
    itemName = name;
    cost = 0;
    pointWorth = pts;
}

float MenuItem::getCost()const{
    return cost;
}
void MenuItem::setCost(const float val){
    cost = val;
}

string MenuItem::getItemName()const{
    return itemName;
}
void MenuItem::setItemName(const string name){
    itemName = name;
}

int MenuItem::getPointWorth()const{
    return pointWorth;
}
void MenuItem::setPointWorth(const int pts){
    pointWorth = pts; 
}
// void MenuItem::displayNameAndCost() const{
//     cout << itemName << " $" << cost << endl;
// }
float MenuItem::operator+(float jeffery)
{
    return cost + jeffery;
}
ostream& MenuItem::displayItemInformation(ostream& outStream) const
{
    outStream << itemName << " $" << cost << endl;
    return outStream;
}
ostream& operator << (ostream& outStream, const MenuItem& item)
{
    item.displayItemInformation(outStream);
    return outStream;

}