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
    Eigen::Vector3d baTruth(3);
    baTruth << 1.23, 4.56, 7.89;
    Eigen::Vector3d sfaTruth(3);
    sfaTruth << 2.34, 5.67, 8.91;
    Eigen::VectorXd maTruth(6);
    maTruth << 1.12, 2.23, 3.34, 4.45, 5.56, 6.67;
    Eigen::Vector3d bgTruth(3);
    bgTruth << -1.23, -4.56, -7.89;
    Eigen::Vector3d sfgTruth(3);
    sfgTruth << -2.34, -5.67, -8.91;
    Eigen::VectorXd mgTruth(6);
    mgTruth << -1.12, -2.23, -3.34, -4.45, -5.56, -6.67;

    // Check Results
    EXPECT_EQ(baTruth, imuCalibrationData.ba);
    EXPECT_EQ(sfaTruth, imuCalibrationData.sfa);
    EXPECT_EQ(maTruth, imuCalibrationData.ma);
    EXPECT_EQ(bgTruth, imuCalibrationData.bg);
    EXPECT_EQ(sfgTruth, imuCalibrationData.sfg);
    EXPECT_EQ(mgTruth, imuCalibrationData.mg);

}