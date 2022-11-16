//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         JSON Utility Header                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    Header file for JSON Utilities class                                                //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <dataTypes.hpp>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

// JSON Utilities Class
class jsonUtilities {

    // Public Class Members/Functions
    public:
        
        /* @parseMasterConfig
            Inputs:
                fileName: std::string of config file name
            Outputs:
                masterConfig: masterConfig_t struct containing path to lower level configs
            Description:
                Function which parses the Master configuration file
        */
        bool parseMasterConfig(const std::string fileName,
                               masterConfig_t &masterConfig);

        /* @parseImuCalibrationConfig
            Inputs:
                fileName: std::string of config file name
            Outputs:
                imuCalibration: imuCalibrationData_t struct containing accelerometer/gyroscope errors
            Description:
                Function which parses the IMU Calibration configuration file
        */
        bool parseImuCalibrationConfig(const std::string fileName,
                                       imuCalibrationData_t &imuCalibration);

    // Private Class Members/Function
    private:

        /* @parseJson
            Inputs:
                fileName: std::string of config file name
            Outputs:
                data: json object containing contents of file
            Description:
                Function which parses the JSON configuration file
        */
        bool parseJson(const std::string fileName,
                       json &data);

};
