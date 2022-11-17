//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Compensator Thread Class                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    The Compensator Thread class implementation. Intializes the compensator and then    //
//              corrects each IMU measurement that arrives for the estimated bias, scale factor     //
//              and misalignment errors. The compensator takes periodic error estimate updates      //
//              from the Kalman Filter.                                                             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#include <iostream>
#include <thread>
#include "compensatorThread.hpp"

// Initialize Compensator
bool compensatorThread::init(imuCalibrationData_t &imuCalibration) {

    // Extract Inputs
    Eigen::Vector3d ba = imuCalibration.ba;
    Eigen::Vector3d sfa = imuCalibration.sfa;
    Eigen::VectorXd ma = imuCalibration.ma;
    Eigen::Vector3d bg = imuCalibration.bg;
    Eigen::Vector3d sfg = imuCalibration.sfg;
    Eigen::VectorXd mg = imuCalibration.mg;

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
bool compensatorThread::runCompensatorThread(masterConfig_t config) {
    
    // Initialize Compensator
    imuCalibrationData_t imuCalibration;
    const std::string calConfig = config.configPath + config.imuCalibrationFile;
    if (!ju_.parseImuCalibrationConfig(calConfig, imuCalibration)) {
        std::cout << "[compensatorThread::runCompensatorThread] Failed to load compensator data" << std::endl;
        return false;
    }
    if (!init(imuCalibration)) {
        std::cout << "[compensatorThread::runCompensatorThread] Failed to initialize compensator" << std::endl;
        return false;
    }

    // Main Loop to Compensate Measurements

    // Successful Return
    std::cout << "[compensatorThread::runCompensatorThread] Terminating Compensator Thread" << std::endl;
    return true;

}