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
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/compensatorThread.hpp
	        ${PROJECT_SOURCE_DIR}/include/strapdownThread.hpp
		${PROJECT_SOURCE_DIR}/include/kalmanFilterThread.hpp)

# Include Directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add Executable
add_executable(GpsInsNavigation ${PROJECT_SOURCE_DIR}/src/main.cpp
	                        ${PROJECT_SOURCE_DIR}/src/compensatorThread.cpp 
				${PROJECT_SOURCE_DIR}/src/strapdownThread.cpp
				${PROJECT_SOURCE_DIR}/src/kalmanFilterThread.cpp ${HEADER_LIST})

# Link Libraries

# Unit Testing Build
