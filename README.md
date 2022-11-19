![image](doc/GPS-INS-Logo.PNG)

# A Robust and High Performance GPS-Aided Inertial Navigation for Geodetic Applications

GPS-INS is a robust, unit tested C++ implementation of a GPS-Aided Inertial Navigation system designed for use in Geodetic applications. The application runs three threads in parallel, one performing inertial measurement error compensation, one running high-rate strapdown integration and one running a Kalman Filter which fuses external measurements and estimates errors in the navigation solution.  

# Dependencies
* C++ 11 (or greater) <br />
* ROS2 <br />
* CMake (3.22.0 or greater) <br />
* Eigen (3.3 or greater) <br />
* GoogleTest <br />
* NavFuse: https://github.com/ParkerBarrett959/NavFuse <br />
* nlohmann JSON

# Build
```
mkdir build
cd build
cmake ..
make
```

# Configuration File Setup
Prior to running the GPS-INS executable, you must edit the system configuration files to match your build paths on your current system. Two changes are needed. 
* In GPS-INS/config/master_config.json, set the "config_path" field to the path of the GPS-INS/config directory on your local machine
* In GPS-INS/test/testData/master_config_unit_test.json, set the "config_path" field to the path of the GPS-INS/test/testData directory on your local machine

# Run Executable
```
./GpsInsNavigation </path/to>/GPS-INS/config/master_config.json
```

# Run Unit Tests
```
./test_gps_ins
```
