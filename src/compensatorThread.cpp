//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Compensator Thread Class                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    The Compensator Thread class implementation. Intializes the compensator and then    //
//              corrects each IMU measurement that arrives for the estimated bias, scale factor     //
//              and misalignment errors. The compensator takes periodic error estimate updates      //
//              from the Kalman Filter.                                                          //                                                                         //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#include <iostream>
#include <thread>
#include "compensatorThread.hpp"

// Initialize Compensator
bool compensatorThread::init(Eigen::Vector3d &ba,
                             Eigen::VectorXd &ma,
                             Eigen::Vector3d &sfa,
                             Eigen::Vector3d &bg,
                             Eigen::VectorXd &mg,
                             Eigen::Vector3d &sfg) {

    // Set Accelerometer Errors
    if (!compensator_.setAccelerometerErrors(ba, ma, sfa)) {
        std::cout << "[compensatorThread::init] Failed to set accelerometer errors" << std::endl;
        return false;
    }

    // Set Gyroscope Errors
    if (!compensator_.setGyroscopeErrors(bg, mg, sfg)) {
        std::cout << "[compensatorThread::init] Failed to set gyroscope errors" << std::endl;
        return false;
    }

    // Successful Return
    return true;

}

// Run Compensator Thread
bool compensatorThread::runCompensatorThread() {
    
    // Initialize Compensator
    Eigen::Vector3d ba = Eigen::Vector3d::Zero(); //temp
    Eigen::VectorXd ma = Eigen::VectorXd::Zero(6); //temp
    Eigen::Vector3d sfa = Eigen::Vector3d::Zero(); //temp
    Eigen::Vector3d bg = Eigen::Vector3d::Zero(); //temp
    Eigen::VectorXd mg = Eigen::VectorXd::Zero(6); //temp
    Eigen::Vector3d sfg = Eigen::Vector3d::Zero();//temp
    if (!init(ba, ma, sfa, bg, mg, sfg)) {
        std::cout << "[compensatorThread::runCompensatorThread] Failed to initialize compensator" << std::endl;
        return false;
    }

    // Main Loop to Compensate Measurements

    // Successful Return
    std::cout << "[compensatorThread::runCompensatorThread] Terminating Compensator Thread" << std::endl;
    return true;

}