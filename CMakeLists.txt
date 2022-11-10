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
include(FetchContent)
FetchContent_Declare(NavFuse
	GIT_REPOSITORY git@github.com:ParkerBarrett959/NavFuse
	GIT_TAG main)
FetchContent_MakeAvailable(NavFuse)
FetchContent_Declare(json
        GIT_REPOSITORY git@github.com:nlohmann/json
        GIT_TAG v3.11.2)
FetchContent_MakeAvailable(json)

# Add Header List
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/compensatorThread.hpp
	        ${PROJECT_SOURCE_DIR}/include/strapdownThread.hpp
		${PROJECT_SOURCE_DIR}/include/kalmanFilterThread.hpp
		${PROJECT_SOURCE_DIR}/include/util/jsonUtilities.hpp)

# Include Directories
include_directories(${PROJECT_SOURCE_DIR}/include
	            ${PROJECT_SOURCE_DIR}/include/util)

# Add Executable
add_executable(GpsInsNavigation ${PROJECT_SOURCE_DIR}/src/main.cpp
	                        ${PROJECT_SOURCE_DIR}/src/compensatorThread.cpp 
				${PROJECT_SOURCE_DIR}/src/strapdownThread.cpp
				${PROJECT_SOURCE_DIR}/src/kalmanFilterThread.cpp 
				${PROJECT_SOURCE_DIR}/src/util/jsonUtilities.cpp ${HEADER_LIST})

# Link Libraries
target_link_libraries(GpsInsNavigation navigation
	                               nlohmann_json::nlohmann_json)

# Target Include Directories
target_include_directories(GpsInsNavigation PUBLIC ${PROJECT_SOURCE_DIR}/include
	                                    PUBLIC ${PROJECT_SOURCE_DIR}/include/util})

# Unit Testing Build
