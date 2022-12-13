cmake_minimum_required(VERSION 3.10)
project(code_test)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(
 include
#  ${CERES_INCLUDE_DIRS}
)

set(CMAKE_CXX_STANDARD 17)

# add_executable(Mat src/01_Mat.cpp)

# add_executable(Image src/02_Image.cpp)

# add_executable(Trackbar src/03_Trackbar.cpp)

# add_executable(Blur src/04_Blur.cpp)

# add_executable(Roi src/05_Roi.cpp)

# add_executable(Mouse src/06_MouseCallBack.cpp)

add_executable(Mouse2 src/07_MouseCallBack2.cpp)

add_executable(Mouse3 src/07-1_MouseCallBack2-1.cpp)

add_executable(Histogram src/08_Histogram.cpp)



# target_link_libraries( Mat ${OpenCV_LIBS} )

# target_link_libraries( Image ${OpenCV_LIBS} )

# target_link_libraries( Trackbar ${OpenCV_LIBS} )

# target_link_libraries( Blur ${OpenCV_LIBS} )

# target_link_libraries( Roi ${OpenCV_LIBS} )

# target_link_libraries( Mouse ${OpenCV_LIBS} )

target_link_libraries( Mouse2 ${OpenCV_LIBS} )

target_link_libraries( Mouse3 ${OpenCV_LIBS} )

target_link_libraries( Histogram ${OpenCV_LIBS} )