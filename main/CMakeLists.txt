set(Main_SRCS
    main.cpp
)

add_executable(restaurant
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(restaurant
    dynamicArray
    customer
    drink
    food
    helperFunctions
    menuItem
    #tests
)
#add_library(helperFunctions STATIC ${helperFunctions_SRCS})
install(TARGETS restaurant DESTINATION bin)