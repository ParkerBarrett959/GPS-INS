//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                GPS-Aided Inertial Navigation System                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    The main GPS-Aided Inertial Navigation system executable. This top level            //
//              executable creates the navigation thread which runs the strapdown integrator, INS   //
//              measurement compensator and error state extended Kalman Filter. It also sets up     //
//              the ROS publishers and subscribers.                                                 //                                                                         //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#include <iostream>
#include <thread>
#include <queue>
#include "compensatorThread.hpp"
#include "strapdownThread.hpp"
#include "kalmanFilterThread.hpp"

// Main GPS-INS Function
int main(int argc, char **argv) {

    // Unpack Inputs

    // Create Compensator Queues
    std::queue<Eigen::Vector3d> deltaVelQueueIn;
    std::queue<Eigen::Vector3d> deltaThetaQueueIn;
    std::queue<Eigen::Vector3d> deltaVelQueueOut;
    std::queue<Eigen::Vector3d> deltaThetaQueueOut;

    // Create Output Queues
    
    // Create ROS Input Subscribers

    // Create ROS Output Publishers

    // Measurement Compensator Thread
    compensatorThread ct;
    std::thread compensatorThread(&compensatorThread::runCompensatorThread, ct);

    // Strapdown Integration Thread
    strapdownThread st;
    std::thread strapdownThread(&strapdownThread::runStrapdownThread, st);

    // Kalman Filter Thread
    kalmanFilterThread kft;
    std::thread kalmanFilterThread(&kalmanFilterThread::runKalmanFilterThread, kft);

    // Terminate Program - Close Threads
    compensatorThread.join();
    strapdownThread.join();
    kalmanFilterThread.join();
    
    // Successful Return
    return 0;

}