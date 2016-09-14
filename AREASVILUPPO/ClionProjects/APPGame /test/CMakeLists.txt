cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp CollEntityTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)

set(CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/CMake_Modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2.3 COMPONENTS system window graphics audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runAllTests ${SFML_LIBRARIES})
endif()