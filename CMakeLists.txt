cmake_minimum_required(VERSION 2.8.12)

project(BitVector)

set(CMAKE_CXX_STANDARD 20)

set(TESTS "OFF" CACHE BOOL "Is it need to compile tests?")

include_directories(src/func)
include_directories(src/BitVector)

if(${TESTS})
	message(NOTICE "The testing mode is selected")
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
	include_directories(tests/func-t)
	include_directories(tests/BitVector-t)
	set(MAIN_SRC tests/main-t.cpp)
	add_executable(run ${MAIN_SRC})
	target_link_libraries(run ${GTEST_LIBRARIES} pthread)
else()
	set(MAIN_SRC src/main.cpp)
	add_executable(run ${MAIN_SRC})
endif()
