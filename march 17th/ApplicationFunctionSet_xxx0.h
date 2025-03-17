/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2024-03-12
 * @Description: Smart Robot Car V4.0
 */

#ifndef _ApplicationFunctionSet_xxx0_H_
#define _ApplicationFunctionSet_xxx0_H_

#include <Arduino.h>

/* Movement Direction Control List */
enum SmartRobotCarMotionControl
{
  Forward,       
  Backward,      
  Left,          
  Right,         
  LeftForward,   
  LeftBackward,  
  RightForward,  
  RightBackward, 
  stop_it        
};

/* Mode Control List */
enum SmartRobotCarFunctionalModel
{
  Standby_mode,           
  TraceBased_mode,        
  ObstacleAvoidance_mode, 
  Follow_mode,            
  Rocker_mode,
  CMD_inspect,     
  CMD_Programming_mode,                  
  CMD_ClearAllFunctions_Standby_mode,     
  CMD_ClearAllFunctions_Programming_mode, 
  CMD_MotorControl,                       
  CMD_CarControl_TimeLimit,               
  CMD_CarControl_NoTimeLimit,             
  CMD_MotorControl_Speed,                 
  CMD_ServoControl,                       
  CMD_LightingControl_TimeLimit,          
  CMD_LightingControl_NoTimeLimit         
};

/* Application Management Struct */
struct Application_xxx
{
  SmartRobotCarMotionControl Motion_Control;
  SmartRobotCarFunctionalModel Functional_Mode;
  unsigned long CMD_CarControl_Millis;
  unsigned long CMD_LightingControl_Millis;
};

extern Application_xxx Application_SmartRobotCarxxx0;

class ApplicationFunctionSet
{
public:
  void ApplicationFunctionSet_Init(void);
  void ApplicationFunctionSet_Bootup(void);
  void ApplicationFunctionSet_RGB(void);
  void ApplicationFunctionSet_Expression(void);
  void ApplicationFunctionSet_Rocker(void);             
  void ApplicationFunctionSet_Tracking(void);           
  void ApplicationFunctionSet_Obstacle(void);           
  void ApplicationFunctionSet_Follow(void);             
  void ApplicationFunctionSet_Servo(uint8_t Set_Servo); 
  void ApplicationFunctionSet_Standby(void);            
  void ApplicationFunctionSet_KeyCommand(void);         
  void ApplicationFunctionSet_SensorDataUpdate(void);   
  void ApplicationFunctionSet_SerialPortDataAnalysis(void);
  void ApplicationFunctionSet_IRrecv(void);
 

public: /* CMD */
  void CMD_UltrasoundModuleStatus_xxx0(uint8_t is_get);
  void CMD_TraceModuleStatus_xxx0(uint8_t is_get);
  void CMD_Car_LeaveTheGround_xxx0(uint8_t is_get);
  void CMD_inspect_xxx0(void);
  void CMD_MotorControl_xxx0(void);
  void CMD_MotorControl_xxx0(uint8_t is_MotorSelection, uint8_t is_MotorDirection, uint8_t is_MotorSpeed);
  void CMD_CarControlTimeLimit_xxx0(void);
  void CMD_CarControlTimeLimit_xxx0(uint8_t is_CarDirection, uint8_t is_CarSpeed, uint32_t is_Timer);
  void CMD_CarControlNoTimeLimit_xxx0(void);
  void CMD_CarControlNoTimeLimit_xxx0(uint8_t is_CarDirection, uint8_t is_CarSpeed);
  void CMD_MotorControlSpeed_xxx0(void);
  void CMD_MotorControlSpeed_xxx0(uint8_t is_Speed_L, uint8_t is_Speed_R);
  void CMD_ServoControl_xxx0(void);
  void CMD_VoiceControl_xxx0(uint16_t is_VoiceName, uint32_t is_VoiceTimer);
  void CMD_LightingControlTimeLimit_xxx0(void);
  void CMD_LightingControlTimeLimit_xxx0(uint8_t is_LightingSequence, uint8_t is_LightingColorValue_R, uint8_t is_LightingColorValue_G, uint8_t is_LightingColorValue_B, uint32_t is_LightingTimer);
  void CMD_LightingControlNoTimeLimit_xxx0(void);
  void CMD_LightingControlNoTimeLimit_xxx0(uint8_t is_LightingSequence, uint8_t is_LightingColorValue_R, uint8_t is_LightingColorValue_G, uint8_t is_LightingColorValue_B);
  void CMD_ClearAllFunctions_xxx0(void);

private:
  /* Sensor Raw Values */
  volatile float VoltageData_V;        
  volatile uint16_t UltrasoundData_mm; 
  volatile uint16_t UltrasoundData_cm; 
  volatile int TrackingData_L;         
  volatile int TrackingData_M;         
  volatile int TrackingData_R;         

  /* Sensor Status */
  boolean VoltageDetectionStatus = false;
  boolean UltrasoundDetectionStatus = false;
  boolean TrackingDetectionStatus_R = false;
  boolean TrackingDetectionStatus_M = false;
  boolean TrackingDetectionStatus_L = false;

public:
  boolean Car_LeaveTheGround = true;

  /* Sensor Threshold Settings */
  const float VoltageDetection = 7.00;
  const uint8_t ObstacleDetection = 20;

  String CommandSerialNumber;
  uint8_t Rocker_CarSpeed = 250;
  uint8_t Rocker_temp;

public:
  uint8_t TrackingDetection_S = 250;
  uint16_t TrackingDetection_E = 850;
  uint16_t TrackingDetection_V = 950;

public:
  uint8_t CMD_is_Servo;
  uint8_t CMD_is_Servo_angle;

public:
  uint8_t CMD_is_MotorSelection;
  uint8_t CMD_is_MotorDirection;
  uint8_t CMD_is_MotorSpeed;
  uint32_t CMD_is_MotorTimer;

public:
  uint8_t CMD_is_CarDirection;
  uint8_t CMD_is_CarSpeed;
  uint32_t CMD_is_CarTimer;

public:
  uint8_t CMD_is_MotorSpeed_L;
  uint8_t CMD_is_MotorSpeed_R;

public:
  uint8_t CMD_is_LightingSequence;
  uint8_t CMD_is_LightingColorValue_R;
  uint8_t CMD_is_LightingColorValue_G;
  uint8_t CMD_is_LightingColorValue_B;
  uint32_t CMD_is_LightingTimer;

private:
  uint8_t CMD_is_FastLED_setBrightness = 20;
};

extern ApplicationFunctionSet Application_FunctionSet;

#endif
