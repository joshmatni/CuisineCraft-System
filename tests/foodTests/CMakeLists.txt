file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(foodTests ${SRCS})
TARGET_LINK_LIBRARIES(foodTests libgtest libgmock menuItem food)
add_test(NAME foodTests COMMAND foodTests)