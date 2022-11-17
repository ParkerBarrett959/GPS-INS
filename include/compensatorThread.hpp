//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Compensator Thread Header                                   //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    Header file for Compensator Thread class                                            //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <compensator.hpp>
#include "jsonUtilities.hpp"

// Compensator Thread Class
class compensatorThread {

    // Public Class Members/Functions
    public:
        
        /* @runCompensatorThread
            Inputs:
            Outputs:
            Description:
                Function which runs the Compensator thread.
        */
        bool runCompensatorThread(masterConfig_t config);

    // Private Class Members/Function
    private:

        /* @init
            Inputs:
                ba: 3x1 vector of accelerometer biases [m/s]
                ma: 6x1 vector of accelerometer misalignments [row major w/ 1's on diagonal]
                sfa: 3x1 vector of accelerometer scale factor errors
                bg: 3x1 vector of gyro biases [rad/s]
                mg: 6x1 vector of gyro misalignments [row major w/ 1's on diagonal]
                sfg: 3x1 vector of gyro scale factor errors
            Outputs:
            Description:
                Function which initializes the Compensator thread.
        */
        bool init(imuCalibrationData_t &imuCalibration);

        // Create Compensator Object
        Compensator compensator_;

        // Create JSON Utility Object
        jsonUtilities ju_;

        // Master Configuration File
        masterConfig_t config_;

};
