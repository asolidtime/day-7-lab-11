/*
 * Project Lab11
 * Description:
 * Author:
 * Date:
 */

SYSTEM_MODE(MANUAL);
#include "Wire.h"
#include "oled-wing-adafruit.h"
#include "LIS3DH.h"
OledWingAdafruit display;
LIS3DHSPI accel(SPI, D3, WKP);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Wire.begin(400000);
  display.setup();
  LIS3DHConfig config;
  config.setAccelMode(LIS3DH::RATE_100_HZ);
  accel.setup(config);
  
  

  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  display.loop();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  LIS3DHSample sample;
  accel.getSample(sample);

  display.print("x: ");
  display.println(sample.x);
  display.print("y: ");
  display.println(sample.y);
  display.print("z: ");
  display.println(sample.z);
  display.display();
}