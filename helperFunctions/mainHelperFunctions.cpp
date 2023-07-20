#include "mainHelperFunctions.h"
//user interaction functions used by main.cpp

template <typename T>
T getUserEntry(){
    T temp;
    cin >> temp;
    return temp;
}



//display related functions used by main.cpp
void displayLoyaltyInformationPrompt(){
    cout << "Enrolling in the Meat Man Mob Loyalty Program is simple!" << endl;
    cout << "Just enter your 7 digit phone number without any dashes and your first and last name!" << endl;
    cout << "For example: 1111111 Pete Wentz" << endl << endl;
}

void displayPointRedemptionMenu(){
    cout << "1.) Sandwich, 450 pts" << endl;
    cout << "2.) Meat Man Meal, 500 pts" << endl;
    cout << "3.) 32 oz. Drink, 50 pts" << endl;
    cout << "4.) Small Tater Tot, 75 pts" << endl;
}

void displayMemberJoin(){
    cout << endl << endl<<"Don't have a loyalty number?" << endl;
    cout << "Join today and earn a free large drink!" << endl;
    cout << "Being a member of the Meat Man Mob Loyalty Program provides the following benefits: " << endl;
    displayPointRedemptionMenu();
    cout << endl<< "Would you like to join the Meat Man Mob Loyalty Program?(y/n) ";
}

void displayMenuItems(){
    cout << endl<< "=====Meaty Meat Man's Restaurant Menu===== " << endl;
    cout << "1.) Smoked Meat Sandwich" << endl;
    cout << "2.) Meaty Meat Man Meal" << endl;
    cout << "3.) Fountain Drink" <<endl;
    cout << "4.) Tater Tots" << endl;
    cout << "0.) Finish Order" << endl;
    cout <<endl<< "Please Enter a Value [0-4]: ";
}



//customer related functions used by main.cpp
Customer* createCustomer(){
    displayLoyaltyInformationPrompt();
    int loyaltyNum = getUserEntry<int>();
    string first = getUserEntry<string>();
    string last = getUserEntry<string>();

    Customer* newMember = new Customer( first, last, loyaltyNum, 50); //dynamically allocate
    return newMember;
}
//MUST DYNAMICALLY ALLOCATE OR DESTRUCTOR CAUSE CRAZINESS
MenuItem& addItemToOrder(int numObject){ //maybe change to if else?
    Food* newFood = new Food;
    Drink* newDrink = new Drink;

    switch(numObject){
        case 1:
            newFood->setCost(12.99);
            newFood->addIngredient("Smoked Meat");
            newFood->addIngredient("White Bread");
            newFood->addIngredient("Mustard");
            newFood->addIngredient("Swiss Cheese");
            newFood->setItemName("Smoked Meat Sandwich");
            newFood->setAvailableExtras();
            promptFoodAddons(*newFood);
            newFood->setPointWorth(450);
            delete newDrink;
            return *newFood;
            break;
        
        case 2: 
            newFood->setCost(15.99);
            newFood->addIngredient("Smoked Meat");
            newFood->addIngredient("Toast");
            newFood->addIngredient("Potatoes");
            newFood->addIngredient("BBQ Sauce");
            newFood->addIngredient("Broccoli");
            newFood->setItemName("Meaty Meat Man Meal");
            newFood->setPointWorth(500);
            newFood->setAvailableExtras();
            promptFoodAddons(*newFood);
            delete newDrink;
            return *newFood;
            break;
        
        case 3: 
            promptDrinkExtras(*newDrink);
            delete newFood;
            return *newDrink;
            break;
        
        case 4:
            newFood->setCost(3.99);
            newFood->addIngredient("Potatoes");
            newFood->addIngredient("Ranch Dressing");
            newFood->setItemName("Tater Tots");
            newFood->setPointWorth(75);
            newFood->setAvailableExtras();
            promptFoodAddons(*newFood);
            delete newDrink;
            return *newFood;
            break;
        case 0: 
            break;
        default:
            cout << "Invalid option entered. Please enter a value [0-4]" << endl;
            break;
    }
}

const DynamicArray<MenuItem*> placeOrder(){
    DynamicArray<MenuItem*> menuItem;
    int userChoice;
    do{
        displayMenuItems();
        userChoice = getUserEntry<int>();
        if(userChoice != 0){
            menuItem.addElementToEndOfArr(&addItemToOrder(userChoice));
        }
        
    }while(userChoice != 0);
    return menuItem;
}



//loyalty related functions used by main.cpp
int runLoyaltyProgram(DynamicArray<Customer*>& customers){ //changed
    int numCustomers = customers.getCurrentNumElementsStored();
    cout <<endl << endl<< "Welcome to Meaty Meat Man's Market!" << endl;
    char loyal;
    char userChoice;
    do{
        cout << endl << "Are you a member of the Meat Man Mob Loyalty Program? (y/n/e to exit): ";
        loyal = getUserEntry<char>();
        userChoice = '.';
    }while(loyal != 'y' && loyal != 'Y' && loyal != 'n' && loyal != 'N'  && loyal != 'e' && loyal != 'E');
    if(loyal == 'e' || loyal == 'E'){
        return -2;
    }

    do{
        if (loyal == 'y' || loyal == 'Y'){
            cout << endl<<"Please enter your loyalty number: ";
            int loyaltyNumber = getUserEntry<int>();
            for(int i = 0; i < numCustomers; i++){ 
                if(customers.getElementAtIndex(i)->getLoyaltyNumber() == loyaltyNumber){
                    customers.getElementAtIndex(i)->displayCustomerInformation();
                    return i;
                }
            }
            loyal = 'N';
        }
        if(loyal == 'N' || loyal == 'n'){
            char join;
            do{
                displayMemberJoin();
                join = getUserEntry<char>();
            }while(join != 'y' && join != 'Y' && join != 'n' && join != 'N');
            if(join != 'y' && join != 'Y'){        
                return -1;
            }
            if(join == 'Y' || join == 'y'){
                Customer* newMember = createCustomer();
                customers.addElementToEndOfArr(newMember);
                numCustomers += 1;
                newMember->displayCustomerInformation();
                return (numCustomers)-1;
            }

            
        }
    }while(loyal != 'y' || loyal != 'Y' || loyal != 'n' || loyal != 'N');

    return -1;
}

void getLoyaltyDatabase(DynamicArray<Customer*>& loyaltyCustomers){
    string firstName, lastName;
    long int loyaltyNumber, numberPoints;
    int numCustomers = 0;
    string space = " ";
    ifstream loyaltyMemberStream(LOYALTYFILE); 
    if ( loyaltyMemberStream.is_open() ) { 
        while(loyaltyMemberStream.good()){
            loyaltyMemberStream >> loyaltyNumber >> firstName >> lastName >> numberPoints;
            Customer* newCustomer = new Customer(firstName, lastName, loyaltyNumber, numberPoints);
            loyaltyCustomers.addElementToEndOfArr(newCustomer);
            numCustomers++;
        }
    }
    //return numCustomers; changed
}
void overwriteLoyaltyDatabase(DynamicArray<Customer*>& customers){ //changed 
    int numCustomers = customers.getCurrentNumElementsStored();
    ofstream loyaltyMemberStream(LOYALTYFILE); 
    for(int i = 0; i < numCustomers; i++){
        loyaltyMemberStream << customers.getElementAtIndex(i)->getLoyaltyNumber() << " " << customers.getElementAtIndex(i)->getCustomerFirst() << " " << customers.getElementAtIndex(i)->getCustomerLast() << " " << customers.getElementAtIndex(i)->getNumberLoyaltyPoints();
        if(i!= numCustomers -1){
            loyaltyMemberStream << endl;
        }
    }
}

const bool pointSystemPrompt(const Customer& customer){
    char useLoyalty;
    int availablePts = customer.getNumberLoyaltyPoints();
    if(availablePts >= 50 && customer.getCurrentOrder().getCurrentNumElementsStored()){
        do{
            
            cout << endl << "Would you like to use any of your " <<availablePts<< " Loyalty Points (y/n)? ";
            int temp;
            cin >> useLoyalty;
            
        }while(useLoyalty != 'y' && useLoyalty != 'Y' && useLoyalty != 'n' && useLoyalty != 'N');
        if((useLoyalty == 'N' || useLoyalty == 'n') ){
            cout << "Cool, we'll bank those points for later!" <<endl;
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}

void useLoyalty(Customer& customer, int availablePts){
    int userOption, numPts;
    string foodName; 

    do{
        displayPointRedemptionMenu();
        cout << "0.) I've changed my mind!" << endl;
        cout << endl<< "Which offer would you like to redeem? [0-4] ";
        userOption = getUserEntry<int>();
        numPts = getNumberOfPointsToRedeem(foodName, userOption);
        bool found = false;
        int ptsToAdd = customer.calculateCost();
        availablePts+=ptsToAdd;
        for( int i=0; i < customer.getCurrentOrder().getCurrentNumElementsStored(); i++){

            if(customer.getCurrentOrder().getElementAtIndex(i)->getItemName() == foodName){
                found = true;
                if(numPts <= availablePts){
                    availablePts -= numPts;
                    customer.getCurrentOrder().getElementAtIndex(i)->setCost(0);
                }
                else{
                    cout << endl<< "Insufficient number of points! Try again another time :) " << endl << endl;

                }

            }
        }
        
        if(!found){
            cout <<endl << "Sorry you didn't order that! Try again another time :)" << endl << endl;
            userOption = -1;
        }
        customer.setNumberLoyaltyPoints(availablePts);

    } while((userOption < -1 || userOption >4));
}

int getNumberOfPointsToRedeem(string &foodName, int userOption){
    int numPts;
    switch(userOption){
        case 1:
            foodName = "Smoked Meat Sandwich";
            numPts = 450;
            break;
        case 2:
            foodName = "Meaty Meat Man Meal";
            numPts = 500;
            break;
        case 3:
            foodName = "Fountain Drink";
            numPts = 50;
            break;
        case 4:
            foodName = "Tater Tots";
            numPts = 75;
            break;
        case 0:
            break;
    }
    return numPts;
}


//cash management used by main.cpp
const void calculateChange(const Customer& currentCustomer){
    float customerMoney = 0;
    do{
        if(currentCustomer.calculateCost() != 0){
            cout << endl << endl << "Please enter the amount you'd like to pay with: $";
            cin >> customerMoney;
            if(customerMoney < currentCustomer.calculateCost()){
                cout << "Insufficient Funds, Trying Again..." << endl;
            }
            else{
                cout << "Your change today is: $" << std::fixed <<setprecision(2) <<customerMoney - currentCustomer.calculateCost() << endl;
            }
        }
    }while(customerMoney < currentCustomer.calculateCost());
}

//food
void promptFoodAddons(Food& newFood){
    char userResponse;
    do{
        cout << "Would you like to add any additional ingredients? (y/n): ";
        userResponse = getUserEntry<char>();
    }while(userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N');
    if(userResponse == 'y' || userResponse == 'Y'){
        selectIngredient(newFood);
    }

}
void selectIngredient(Food& newFood){
    int userEntry;
    cout << endl << "AVAILABLE ADD ONS" << endl<<endl;
    for(int i = 0; i < newFood.getNumAvailableExtras(); i++){
        cout << i + 1 << ". " <<  newFood.getAvailableExtras().getElementAtIndex(i) << endl;
    }
    cout << newFood.getNumAvailableExtras() +1 << ". Done adding" << endl << endl;
    do{
        cout << "What would you like to add? ";
        userEntry = getUserEntry<int>();
        if (userEntry > 0 && userEntry < newFood.getNumAvailableExtras()){
            newFood.addIngredient(newFood.getAvailableExtras().getElementAtIndex(userEntry-1));
        }
    }while((userEntry < newFood.getNumAvailableExtras() || userEntry> newFood.getNumAvailableExtras()) && userEntry != newFood.getNumAvailableExtras() +1);
    newFood.calculateMenuItemCost();
}

//drink
void promptDrinkExtras(Drink& newDrink){
    int numOz;
    do{
        cout << "What size? (16, 20, 32) oz: ";
        numOz = getUserEntry<int>();
        newDrink.setSize(numOz);
    }while(numOz != 16 && numOz != 20 && numOz != 32 );

    cout << "Would you like a straw? (y/n): ";
    char userResponse;
    do{
        userResponse = getUserEntry<char>();
        if(userResponse == 'y' || userResponse=='Y'){
            newDrink.setNeedsStraw(true);
        }
    }while(userResponse != 'n' && userResponse!= 'N' && userResponse != 'y' && userResponse != 'Y');


    cout << "Would you like ice? (y/n): ";
    do{
        userResponse = getUserEntry<char>();
        if(userResponse == 'y' || userResponse == 'Y'){
            newDrink.setNeedsIce(true);
        }
    }while(userResponse != 'n' && userResponse != 'N'&& userResponse != 'y' && userResponse != 'Y');

    newDrink.calculateMenuItemCost();
}