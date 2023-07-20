#include "gtest/gtest.h"
#include "../../customer/customer.h"


TEST(customerTests, displayCustomerInformation)
{
    Customer customer("Jeffery", "Cat", 1234567, 50);
    testing::internal::CaptureStdout(); //saves output
    customer.displayCustomerInformation();
    string output = testing::internal::GetCapturedStdout(); //set equal output to a variable
    ASSERT_EQ(output, "\nWelcome Jeffery Cat!\nYou have 50 Loyalty Points.\n"); //compare function to expected output
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}