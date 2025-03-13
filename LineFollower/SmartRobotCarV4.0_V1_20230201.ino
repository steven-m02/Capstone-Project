
#include <avr/wdt.h>  // Include Watchdog Timer library
#include "ApplicationFunctionSet_xxx0.h"
void setup() {
    // Initialize system
    Serial.begin(9600);
    Application_FunctionSet.ApplicationFunctionSet_Init();
}


void loop()
{
  wdt_reset();  // Reset watchdog timer to prevent system reset

  // Update sensor data
  Application_FunctionSet.ApplicationFunctionSet_SensorDataUpdate();

  // Select the correct function based on the active mode
  switch (Application_SmartRobotCarxxx0.Functional_Mode)
  {
    case TraceBased_mode:  // Line Tracking Mode
      Serial.println("Line Tracking Mode Active...");
      Application_FunctionSet.ApplicationFunctionSet_Tracking();
      break;

    case ObstacleAvoidance_mode:  // Obstacle Avoidance Mode
      Serial.println("Obstacle Avoidance Mode Active...");
      Application_FunctionSet.ApplicationFunctionSet_Obstacle();
      break;

    case Follow_mode:  // Object Following Mode
      Serial.println("Object Following Mode Active...");
      Application_FunctionSet.ApplicationFunctionSet_Follow();
      break;

    case Rocker_mode:  // Remote Control Mode
      Serial.println("Remote Control Mode Active...");
      Application_FunctionSet.ApplicationFunctionSet_Rocker();
      break;

    case Standby_mode:  // Standby Mode (Idle)
      Serial.println("Standby Mode Active...");
      Application_FunctionSet.ApplicationFunctionSet_Standby();
      break;

    default:
      Serial.println("Unknown Mode... Entering Standby.");
      Application_FunctionSet.ApplicationFunctionSet_Standby();
      break;
  }

  // Handle remote control, sensors, and commands
  Application_FunctionSet.ApplicationFunctionSet_KeyCommand();
  Application_FunctionSet.ApplicationFunctionSet_IRrecv();
  Application_FunctionSet.ApplicationFunctionSet_SerialPortDataAnalysis();

  // Control RGB LED lighting effects
  Application_FunctionSet.ApplicationFunctionSet_RGB();

  // Execute commands received from the remote or app
  Application_FunctionSet.CMD_ServoControl_xxx0();
  Application_FunctionSet.CMD_MotorControl_xxx0();
  Application_FunctionSet.CMD_CarControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_CarControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_MotorControlSpeed_xxx0();
  Application_FunctionSet.CMD_LightingControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_LightingControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_ClearAllFunctions_xxx0();
}
