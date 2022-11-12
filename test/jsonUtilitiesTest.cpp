//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      JSON Utilities Unit Testing                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    JSON Utilities Class Unit Tests.                                                    //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Statements
#include "gtest/gtest.h"
#include "jsonUtilities.hpp"
#include <Eigen/Dense>
#include <string>

// Parse IMU Calibration Config Unit Test
TEST(ParseConfig, ImuCalibration)
{

    // Create JSON Utilities Object
    jsonUtilities ju;

    // Create IMU Calibration Data
    imuCalibrationData_t imuCalibrationData;

    // Parse IMU Calibration Config
    const std::string fileName = "../test/testData/imu_calibration_unit_test.json";

    // Successfully Parse IMU Calibration Config 
    EXPECT_TRUE(ju.parseImuCalibrationConfig(fileName, imuCalibrationData));

    // Define Expected Results
    //Eigen::Vector3d baTruth(3);
    //baTruth << 1.23, 4.56, 7.89;

    // Check Results
    //EXPECT_EQ(baTruth, imuCalibrationData.ba);

}