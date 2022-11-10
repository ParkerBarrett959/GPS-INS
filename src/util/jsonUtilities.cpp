//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Compensator Thread Class                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    The JSON Utilities class. This class implementation contains useful functions for   //
//              parsing the JSON configuration files used by the system.                            //                                                          //                                                                         //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#include <iostream>
#include <thread>
#include "jsonUtilities.hpp"

// Parse IMU Calibration Configuration File
bool jsonUtilities::parseImuCalibrationConfig(const std::string fileName,
                                              imuCalibrationData_t &imuCalibration) {

    // Read in File
    json config;
    if (!parseJson(fileName, config)) {
        std::cout << "[jsonUtilities::parseImuCalibrationConfig] Failed to parse IMU Calibration Config" << std::endl;
        return false;
    }

    // Insert Parsing Here

    // Successful Return
    return true;

}

// Parse JSON File
bool jsonUtilities::parseJson(const std::string fileName,
                              json &data) {

    // Read in File
    std::ifstream file(fileName);
    if (!file.good()) {
        std::cout << "[jsonUtilities::parseJson] Invalid JSON file path" << std::endl;
        return false;
    }

    // Parse File
    data = json::parse(file);

    // Successful Return
    return true;

}