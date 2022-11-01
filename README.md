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

# Build
```
mkdir build
cd build
cmake ..
make
```
