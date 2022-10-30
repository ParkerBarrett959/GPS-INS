###################################################################
#       Cmake Build of GPS-Aided Inertial Navigation System       #
###################################################################

# Project Setup
cmake_minimum_required(VERSION 3.22.0)
project(gps_aided_ins)
set(CMAKE_CXX_STANDARD 11)

# External Dependencies
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

# Add Header List

# Add Executable
add_executable(GpsInsNavigation ${PROJECT_SOURCE_DIR}/src/main.cpp)

# Unit Testing Build
