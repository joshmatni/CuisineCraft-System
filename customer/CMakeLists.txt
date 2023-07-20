set(customer_SRCS customer.h customer.cpp)

add_library(customer STATIC ${customer_SRCS})

target_link_libraries(customer menuItem)

target_include_directories(customer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})