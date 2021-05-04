cmake_minimum_required(VERSION 3.17)
project(LBP_OpenMP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fopenmp")

include_directories(.)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(LBP_OpenMP LocalBinaryPattern.cpp LocalBinaryPattern.h main.cpp writeCsv.cpp writeCsv.h)
add_executable(timeTests runTests.cpp execTimeTests.cpp execTimeTests.h LocalBinaryPattern.cpp LocalBinaryPattern.h writeCsv.cpp writeCsv.h)

target_link_libraries(LBP_OpenMP ${OpenCV_LIBS})
target_link_libraries(timeTests ${OpenCV_LIBS})
