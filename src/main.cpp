/**********************************************************************
  Filename    : SerialToSerialBT
  Description : ESP32 communicates with the phone by bluetooth and print phone's
data via a serial port Auther      : www.freenove.com Modification: 2020/07/11
**********************************************************************/
#include <Arduino.h>

#include "BluetoothSerial.h"

#define RXD2 33
#define TXD2 4

BluetoothSerial SerialBT;
String buffer;
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  SerialBT.begin("Elegoo Smart Car 4.0");  // Bluetooth device name
  Serial.println("\nThe device started, now you can pair it with bluetooth!");
}

void loop() {
  // Serial.println("Hello, this is Serial0 speaking.");
  // Serial2.println("Hello, this is Serial2 speaking.");

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (Serial2.available()) {
    SerialBT.write(Serial2.read());
  }
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.write(c);
    Serial2.write(c);
  }
  delay(20);
}