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

    // Get Accelerometer JSON Object
    json accel = config["accelerometer"];

    // Get Accelerometer Bias, Scale Factor and Misalignment
    json ba = accel["bias"];
    json sfa = accel["scale_factor"];
    json ma = accel["misalignment"];
    
    // Get Accelerometer Bias and Set Output
    double ba_X = ba.value("x_body",0.0);
    double ba_Y = ba.value("y_body",0.0);
    double ba_Z = ba.value("z_body",0.0);
    imuCalibration.ba << ba_X, ba_Y, ba_Z;
    
    // Get Accelerometer Scale factor Error and Set Output
    double sfa_X = sfa.value("x_body",0.0);
    double sfa_Y = sfa.value("y_body",0.0);
    double sfa_Z = sfa.value("z_body",0.0);
    imuCalibration.sfa << sfa_X, sfa_Y, sfa_Z;
    
    // Get Accelerometer Misalignment and Set Output
    double ma_1 = ma.value("m1",0.0);
    double ma_2 = ma.value("m2",0.0);
    double ma_3 = ma.value("m3",0.0);
    double ma_4 = ma.value("m4",0.0);
    double ma_5 = ma.value("m5",0.0);
    double ma_6 = ma.value("m6",0.0);
    imuCalibration.ma = Eigen::VectorXd(6);
    imuCalibration.ma << ma_1, ma_2, ma_3, ma_4, ma_5, ma_6;
    
    // Get Gyroscope JSON Object
    json gyro = config["gyroscope"];

    // Get Gyroscope Bias, Scale Factor and Misalignment
    json bg = gyro["bias"];
    json sfg = gyro["scale_factor"];
    json mg = gyro["misalignment"];

    // Get Gyroscope Bias and Set Output
    double bg_X = bg.value("x_body",0.0);
    double bg_Y = bg.value("y_body",0.0);
    double bg_Z = bg.value("z_body",0.0);
    imuCalibration.bg << bg_X, bg_Y, bg_Z;

    // Get Gyroscope Scale Factor Error and Set Output
    double sfg_X = sfg.value("x_body",0.0);
    double sfg_Y = sfg.value("y_body",0.0);
    double sfg_Z = sfg.value("z_body",0.0);
    imuCalibration.sfg << sfg_X, sfg_Y, sfg_Z;

    // Get Gyroscope Misalignment and Set Output
    double mg_1 = mg.value("m1",0.0);
    double mg_2 = mg.value("m2",0.0);
    double mg_3 = mg.value("m3",0.0);
    double mg_4 = mg.value("m4",0.0);
    double mg_5 = mg.value("m5",0.0);
    double mg_6 = mg.value("m6",0.0);
    imuCalibration.mg = Eigen::VectorXd(6);
    imuCalibration.mg << mg_1, mg_2, mg_3, mg_4, mg_5, mg_6;

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