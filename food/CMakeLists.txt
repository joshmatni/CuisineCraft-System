set(food_SRCS food.h food.cpp)

add_library(food STATIC ${food_SRCS})

target_link_libraries(food menuItem)

target_include_directories(food PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})