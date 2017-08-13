cmake_minimum_required (VERSION 3.6)
project (Ngoding)

set (CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "-std=c++11")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set (SOURCE_FILES PenyisihanCompfest9/B.cpp PenyisihanCompfest9/G.cpp)
add_executable (Ngoding ${SOURCE_FILES})