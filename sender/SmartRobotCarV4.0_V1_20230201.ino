  /*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-12-18 14:14:35
 * @LastEditors: Changhua
 * @Description: Smart Robot Car V4.0
 * @FilePath: 
 */
#include <avr/wdt.h>
#include "ApplicationFunctionSet_xxx0.h"
#include <ESP8266WiFi.h>  // For Wi-Fi communication


// Replace with your Wi-Fi network credentials
const char* ssid = "Capstone123";
const char* password = "CapstonePassword123";


void setup()
{
  // Initialize robot functionalities
  Application_FunctionSet.ApplicationFunctionSet_Init();
  
  // Initialize Wi-Fi connection
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Display IP for the master robot
  
  server.begin();  // Start server if this is the master robot
  
  // Enable watchdog timer
  wdt_enable(WDTO_2S);
}

void loop()
{
  // Existing robot functionalities (unchanged)
  wdt_reset();
  Application_FunctionSet.ApplicationFunctionSet_SensorDataUpdate();
  Application_FunctionSet.ApplicationFunctionSet_KeyCommand();
  Application_FunctionSet.ApplicationFunctionSet_RGB();
  Application_FunctionSet.ApplicationFunctionSet_Follow();
  Application_FunctionSet.ApplicationFunctionSet_Obstacle();
  Application_FunctionSet.ApplicationFunctionSet_Tracking();
  Application_FunctionSet.ApplicationFunctionSet_Rocker();
  Application_FunctionSet.ApplicationFunctionSet_Standby();
  Application_FunctionSet.ApplicationFunctionSet_IRrecv();
  Application_FunctionSet.ApplicationFunctionSet_Autonomous();
  Application_FunctionSet.ApplicationFunctionSet_SerialPortDataAnalysis();

  Application_FunctionSet.CMD_ServoControl_xxx0();
  Application_FunctionSet.CMD_MotorControl_xxx0();
  Application_FunctionSet.CMD_CarControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_CarControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_MotorControlSpeed_xxx0();
  Application_FunctionSet.CMD_LightingControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_LightingControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_ClearAllFunctions_xxx0();

  // New Wi-Fi Communication Logic (Master Server)
  WiFiClient client = server.available();  // Check for incoming connections

  if (client) {
    Serial.println("Robot connected via Wi-Fi");

    // Example: Send forward command to connected robot
    client.println("{\"N\":3,\"D1\":3,\"D2\":100}");  // Move forward at speed 100

    delay(1000);  // Delay before sending the next command

    // Optional: Read response from connected robot
    if (client.available()) {
      String response = client.readStringUntil('\n');
      Serial.print("Response from robot: ");
      Serial.println(response);
    }

    client.stop();  // Close connection after sending commands
    Serial.println("Robot disconnected");
  }
}
