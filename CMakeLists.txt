cmake_minimum_required(VERSION 3.10)
project(code_test)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(
 include
#  ${CERES_INCLUDE_DIRS}
)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mat src/01_Mat.cpp)

add_executable(Image src/02_Image.cpp)

add_executable(Trackbar src/03_Trackbar.cpp)

target_link_libraries( Mat ${OpenCV_LIBS} )

target_link_libraries( Image ${OpenCV_LIBS} )

target_link_libraries( Trackbar ${OpenCV_LIBS} )