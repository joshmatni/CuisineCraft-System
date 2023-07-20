#include "gtest/gtest.h"
#include "../../drink/drink.h"

TEST(foodTests, calculateMenuItemCost)
{
    //Create a drink object with a straw and ice = a cost of $3.99
    Drink testDrink(16, true, true);

    //Calculate expected cost
    float expectedCost = 2.99 + 0.75 + 0.25; 

    //Calculate the actual cost using the calculateMenuItemCost method
    float actualCost = testDrink.calculateMenuItemCost();
    
    //Ensure that the actual cost matches the expected cost
    EXPECT_NEAR(expectedCost, actualCost, 0.001);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}