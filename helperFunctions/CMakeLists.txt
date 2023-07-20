set(helperFunctions_SRCS mainHelperFunctions.h mainHelperFunctions.cpp)

add_library(helperFunctions STATIC ${helperFunctions_SRCS})

target_link_libraries(helperFunctions food drink)

#target_include_directories(helperFunctions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})