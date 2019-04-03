#include "main.h"
#include "systems/config/motors.hpp"
#include "systems/drive.hpp"
#include "systems/ramping.hpp"
namespace Drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,
  okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor back_left_motor(20,false,okapi::AbstractMotor::gearset::green,
  okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor front_right_motor(1,true,okapi::AbstractMotor::gearset::green,
  okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor back_right_motor(10,true,okapi::AbstractMotor::gearset::green,
  okapi::AbstractMotor::encoderUnits::degrees);
Ramping LFDR(1,4,200);
Ramping RFDR(1,4,200);
Ramping LBDR(1,4,200);
Ramping RBDR(1,4,200);
  
  void setMechLFVel(int vel){
    if(vel==0) front_left_motor.moveVelocity(0);
    else front_left_motor.moveVelocity(vel);
  }
  void setMechLBVel(int vel){
    if(vel==0) back_left_motor.moveVelocity(0);
    else back_left_motor.moveVelocity(vel);
  }
  void setMechRFVel(int vel){
    if(vel==0) front_right_motor.moveVelocity(0);
    else front_right_motor.moveVelocity(vel);
  }
  void setMechRBVel(int vel){
    if(vel==0) back_right_motor.moveVelocity(0);
    else back_right_motor.moveVelocity(vel);
  }
  void setMechDriveVel(int LF,int LB,int RF,int RB){
    setMechLFVel(LF);
    setMechLBVel(LB);
    setMechRFVel(RF);
    setMechRBVel(RB);
  }
  void DriveMechVelSend(int j1,int j2,int j3=0,int j4=0){//left,right,side1,side2
    int LF=j1;//left
    int RF=j2;//right
    int SD=(j3+j4)/2;//side

    setMechDriveVel(//left go apart && right go into when going right
      LF+SD,
      LF-SD,
      RF-SD,
      RF+SD);
    }
    void setDriveVel(int left, int right){
      setMechLFVel(left);
      setMechLBVel(left);
      setMechRFVel(right);
      setMechRBVel(right);

    }
  }


  namespace Flipper{
    okapi::Motor motor(19,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
    void setFlipVel(int vel){
      if(vel==0) motor.moveVelocity(0);
      else motor.moveVelocity(vel);
    }
  }


  namespace Lift{
    okapi::Motor motor(9,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
    void setLiftVel(int vel){
      if(vel==0) motor.moveVelocity(0);
      else motor.moveVelocity(vel);
    }
  }
  namespace Catapult{
    okapi::Motor motor(13,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
    pros::ADIAnalogIn ChargeLightSensor(3);
    void setCatapultVel(int vel){
      if(vel==0) motor.moveVelocity(0);
      else motor.moveVelocity(vel);
    }
  }
  namespace Intake{
    okapi::Motor motor(2,false,okapi::AbstractMotor::gearset::blue,okapi::AbstractMotor::encoderUnits::degrees);
    void setIntakeVel(int vel){
      if(vel==0) motor.moveVelocity(0);
      else motor.moveVelocity(vel);
      pros::ADIAnalogIn BallSenseBottom(6);
      pros::ADIAnalogIn BallSenseTop(4);
    }
  }

  /* sensors */
  pros::ADIAnalogIn MainAtonSelect(1);
  pros::ADIAnalogIn SecAtonSelect(2);
