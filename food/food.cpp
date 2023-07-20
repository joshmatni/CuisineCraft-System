#include "food.h"

Food::Food():MenuItem(){
    numberIngredients = 0;
    currentMaxNumberIngredients = MAX_NUMBER_INGREDIENTS;
    setAvailableExtras();
}
Food::Food(const DynamicArray<string> ing, const int numIngredients, string nm, int num):MenuItem(nm, num){
    currentMaxNumberIngredients = MAX_NUMBER_INGREDIENTS;
    numberIngredients = numIngredients;
    for(int i = 0; i < numIngredients; i++){
        ingredients.addElementToEndOfArr(ingredients.getElementAtIndex(i));
    }

    setAvailableExtras();
}
Food::Food(const Food& rhs):MenuItem(rhs){
    currentMaxNumberIngredients = rhs.currentMaxNumberIngredients;
    for(int i = 0; i < rhs.numberIngredients; i++){
        ingredients.addElementToEndOfArr(rhs.ingredients.getElementAtIndex(i));
    }
    numAvailableExtras = rhs.numAvailableExtras;
    for(int i = 0; i < numAvailableExtras; i++){
         availableExtras.addElementToEndOfArr(rhs.availableExtras.getElementAtIndex(i));
    }
}
Food::~Food(){
    //delete [] ingredients;
}

DynamicArray<string> Food::getIngredients(){
    return ingredients;
}
void Food::addIngredient(const string ingredient){

    ingredients.addElementToEndOfArr(ingredient);
    numberIngredients++;
}

int Food::getNumberIngredients()const{
    return numberIngredients;
}

void Food::setAvailableExtras(){
    if(itemName == "Smoked Meat Sandwich"){
        numAvailableExtras = 5;
        availableExtras.addElementToEndOfArr("Toast");
        availableExtras.addElementToEndOfArr("Potatoes");
        availableExtras.addElementToEndOfArr("BBQ Sauce");
        availableExtras.addElementToEndOfArr("Broccoli");
        availableExtras.addElementToEndOfArr("Ranch Dressing");
    }
    else if(itemName == "Meaty Meat Man Meal"){
        numAvailableExtras = 4;
        availableExtras.addElementToEndOfArr("White Bread");
        availableExtras.addElementToEndOfArr("Mustard");
        availableExtras.addElementToEndOfArr("Swiss Cheese");
        availableExtras.addElementToEndOfArr("Ranch Dressing");
    }
    else if(itemName == "Tater Tots"){
        numAvailableExtras = 7;
        availableExtras.addElementToEndOfArr( "Smoked Meat");
        availableExtras.addElementToEndOfArr("White Bread");
        availableExtras.addElementToEndOfArr("Mustard");
        availableExtras.addElementToEndOfArr("Swiss Cheese");
        availableExtras.addElementToEndOfArr("Toast");
        availableExtras.addElementToEndOfArr( "BBQ Sauce");
        availableExtras.addElementToEndOfArr("Broccoli");
    }
}

DynamicArray<string>Food::getAvailableExtras(){
    return availableExtras;
}

int Food::getNumAvailableExtras()const{
    return numAvailableExtras;
}

void Food::calculateMenuItemCost(){
    int numExtrasAdded;
    if(itemName == "Smoked Meat Sandwich"){
        numExtrasAdded = numberIngredients - 4;
    }
    else if(itemName == "Meaty Meat Man Meal"){
        numExtrasAdded = numberIngredients - 5;
    }
    else if(itemName == "Tater Tots"){
        numExtrasAdded = numberIngredients -2;
    }

    if(numExtrasAdded > 0 ){
        cost += (.5 * (double)numExtrasAdded); 
    }
}

ostream& Food::displayItemInformation(ostream& outStream)const{
    MenuItem::displayItemInformation(outStream);
    //displayNameAndCost();
    outStream << "INGREDIENTS: ";
    for(int i = 0; i < numberIngredients; i++){
        outStream << ingredients.getElementAtIndex(i);
        if(i != numberIngredients-1){
            outStream << ", ";
        }
    }
    outStream << endl << endl;
    return outStream;
}

