//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       Kalman Filter Thread Class                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    The Kalman Filter Thread class implementation. Intializes the Kalman Filter and     //
//              then runs, propagating forward in time with the inertial measurements, and making   //
//              periodic GNSS updates as they become available.                                     //                                                                         //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#include <iostream>
#include <thread>
#include "kalmanFilterThread.hpp"

// Run Kalman Filter Thread
bool kalmanFilterThread::runKalmanFilterThread() {
    
    // Initialize Kalman Filter

    // Main Loop to Run Filter

    // Successful Return
    std::cout << "[kalmanFilterThread::runKalmanFilterThread] Terminating Kalman Filter Thread" << std::endl;
    return true;

}