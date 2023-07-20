file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(customerTests ${SRCS})
TARGET_LINK_LIBRARIES(customerTests libgtest libgmock menuItem customer)
add_test(NAME customerTests COMMAND customerTests)