/*!
 * Author: Josh Matni
 * Date: 12/1/2022
 * Purpose: Create restaurant ordering system that tracks customer loyalty
 * Max number of customers for this program is 1000
 * Max number of menuItems is 100
 * Max number of ingredients is 50
 * NOTE: only include NECESSARY .h files and built in libraries in cpp files (you onnly need fstream in driver for example)
*/
#include "../helperFunctions/mainHelperFunctions.h"

int main(){
    //Customer customers[MAX_NUM_CUSTOMERS];
    //Customer* customers = new Customer[STARTING_NUM_CUSTOMERS];
    bool isLoyaltyMember;
    int customerIndex = 95;

    do{ 
        DynamicArray<Customer*> customers;
        getLoyaltyDatabase(customers); //changed
        int numCustomers = customers.getCurrentNumElementsStored();
        customerIndex = runLoyaltyProgram(customers);

        //if negative 2, exit
        if(customerIndex == -2){
            return -2;
        }
        else if(customerIndex == -1){//if -1, not member
            customerIndex = numCustomers;
            customers.addElementToEndOfArr(new Customer());
            isLoyaltyMember = false;
        }
        else{ 
            isLoyaltyMember = true;
        }
        //reset num items and place order
        //customers.getElementAtIndex(customerIndex)->setNumItemsInOrder(0); changed
        // customers.getElementAtIndex(customerIndex);
        DynamicArray<MenuItem*> currentOrder = placeOrder(); //changed
        for(int i = 0; i < currentOrder.getCurrentNumElementsStored(); i++){
            customers.getElementAtIndex(customerIndex)->addItemToOrder(currentOrder.getElementAtIndex(i));
        }
        //if loyalty member, track available points, calculate cost, and prompt to use points
        if(isLoyaltyMember){
            int availablePts = customers.getElementAtIndex(customerIndex)->getNumberLoyaltyPoints();
            int numPts = customers.getElementAtIndex(customerIndex)->calculateCost();
            bool usingLoyalty = pointSystemPrompt(*customers.getElementAtIndex(customerIndex));
            //if not using points, display order, update points by cost, and then calculate change
            float customerMoney = 0;
            if(!usingLoyalty){
                availablePts += numPts;
                //customers.getElementAtIndex(customerIndex)->displayOrder();
                cout << customers.getElementAtIndex(customerIndex) << endl; //added
                customers.getElementAtIndex(customerIndex)->setNumberLoyaltyPoints(availablePts);
                calculateChange(*customers.getElementAtIndex(customerIndex));
                cout<< "Have a nice day, and thank you for choosing Meaty Meat Man's Market!" << endl << endl <<endl << endl;
            }
            else{
                //if using points, update number of available points (cost of meal added, item subtracted), display order, and calculate points
                useLoyalty(*customers.getElementAtIndex(customerIndex), availablePts); //changed
                //customers.getElementAtIndex(customerIndex)->displayOrder();
                cout << customers.getElementAtIndex(customerIndex) << endl; //added
                calculateChange(*customers.getElementAtIndex(customerIndex));
                cout<< "Have a nice day, and thank you for choosing Meaty Meat Man's Market!" << endl << endl <<endl << endl;
            }
        }
        else{
            //if not member, display order, calculate change
            //customers.getElementAtIndex(customerIndex)->displayOrder();
            cout << customers.getElementAtIndex(customerIndex) << endl; //added
            calculateChange(*customers.getElementAtIndex(customerIndex));
            cout<< "Have a nice day, and thank you for choosing Meaty Meat Man's Market!" << endl << endl <<endl << endl;
            //customers.getElementAtIndex(customerIndex)->setNumItemsInOrder(0); changed
            // customers.getElementAtIndex(customerIndex);
        }
        customers.getElementAtIndex(customerIndex)->clearOrder();
        overwriteLoyaltyDatabase(customers);
    }while(customerIndex != -2);
    
    
    return 0;
}
