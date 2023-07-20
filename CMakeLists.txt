# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(restaurant)

enable_testing()
#add content subdirectories so files can be found
add_subdirectory(main)
add_subdirectory(customer)
add_subdirectory(drink)
add_subdirectory(food)
add_subdirectory(main)
add_subdirectory(menuItem)
add_subdirectory(helperFunctions)
#add_subdirectory(tests)
add_subdirectory(dynamicArray)