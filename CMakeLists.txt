cmake_minimum_required (VERSION 3.4)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_VERBOSE_MAKEFILE TRUE) 

project (SFML_infinit_run)
enable_language(CXX)

set(SOURCE_FILES
    src/main/main.cpp
	src/CollisionDetection.cpp
	src/WallsRepositioning.cpp
    src/Movement.cpp
    src/Animations.cpp
    src/InitialValues.cpp
)

set(EXECUTABLE_NAME "IR")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

target_include_directories(${EXECUTABLE_NAME} PUBLIC inc)

#TESTS_SECTION

set(BOOST_ROOT /usr/local/lib/boost_1_67_0/include)
#set(BOOST_INCLUDE_DIRS /usr/local/lib/boost_1_67_0/include)

find_package(Boost 1.67.0 COMPONENTS "unit_test_framework" REQUIRED)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}inc
    ${Boost_INCLUDE_DIRS})

set(SOURCE_TEST_FILES
    unit-tests/master.cpp
    src/Movement.cpp
    unit-tests/Movement-test.cpp
    src/CollisionDetection.cpp
    unit-tests/Collision-test.cpp)

add_executable(Tests ${SOURCE_TEST_FILES})

target_include_directories(Tests PUBLIC inc)

target_link_libraries (Tests
    ${SFML_LIBRARIES}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

enable_testing()

add_test(Test1 Tests
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )