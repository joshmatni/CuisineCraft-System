#include "gtest/gtest.h"
#include "../../food/food.h"

TEST(foodTests, addIngredient) 
{
  //create a Food object with no ingredients
  Food testFood;

  //add an ingredient to the food object
  testFood.addIngredient("BBQ Sauce");
  
  //get the list of ingredients and number of ingredients
  DynamicArray<string> ingredients = testFood.getIngredients();
  int numIngredients = testFood.getNumberIngredients();
  
  //check that the ingredient was added correctly
  ASSERT_EQ(ingredients.getDynamicArray()[0], "BBQ Sauce");
  ASSERT_EQ(numIngredients, 1);
  
  //add another ingredient to the food object
  testFood.addIngredient("Toast");
  
  //get the updated list of ingredients and number of ingredients
  ingredients = testFood.getIngredients();
  numIngredients = testFood.getNumberIngredients();
  
  //check that both ingredients were added correctly and the numIngredients ==2
  ASSERT_EQ(ingredients.getDynamicArray()[0], "BBQ Sauce");
  ASSERT_EQ(ingredients.getDynamicArray()[1], "Toast");
  ASSERT_EQ(numIngredients, 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}