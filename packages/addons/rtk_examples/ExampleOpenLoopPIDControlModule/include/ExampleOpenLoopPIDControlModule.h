/*
 * Copyright (C) 2010 Learning Algorithms and Systems Laboratory, EPFL, Switzerland
 * Author: Eric Sauser
 * email:   eric.sauser@a3.epf.ch
 * website: lasa.epfl.ch
 *
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

#ifndef MyRobotModule_H_
#define MyRobotModule_H_

#include "RobotLib/RobotInterface.h"

#include "RobotLib/InverseDynamics.h"
#include "RobotLib/PIDController.h"

class ExampleOpenLoopPIDControlModule : public RobotInterface
{
public:

    Robot                       mInternalRobot;
    RevoluteJointSensorGroup    mInternalSensorsGroup;
    RevoluteJointActuatorGroup  mInternalActuatorsGroup;


    RevoluteJointSensorGroup    mSensorsGroup;
    RevoluteJointActuatorGroup  mActuatorsGroup;


    InverseDynamics             mInvDynamics;
    PIDController               mPIDCtrl;


    Vector                      mJointTorques;
    Vector                      mJointTarget;

    int                         mState;

    double                      mStartTime;
public:
            ExampleOpenLoopPIDControlModule();
    virtual ~ExampleOpenLoopPIDControlModule();
  
    virtual Status              RobotInit();
    virtual Status              RobotFree();
  
    virtual Status              RobotStart();    
    virtual Status              RobotStop();
  
    virtual Status              RobotUpdate();
    virtual Status              RobotUpdateCore();

    virtual int                 RespondToConsoleCommand(const string cmd, const vector<string> &args);
};



#endif 
