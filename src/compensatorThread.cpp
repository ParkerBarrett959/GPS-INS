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

// Run Compensator Thread
bool compensatorThread::runCompensatorThread() {
    
    // Initialize Compensator

    // Main Loop to Compensate Measurements

    // Successful Return
    std::cout << "[compensatorThread::runCompensatorThread] Terminating Compensator Thread" << std::endl;
    return true;

}