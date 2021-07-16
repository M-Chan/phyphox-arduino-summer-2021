/*
Link between Arduino Nano 33 BLE IMU and phyphox app v1
Allows to choose which experiment the Arduino Nano 33 BLE Sense should execute, using Phyphox.
by Gautier Creutzer and Frédéric Bouquet, La Physique Autrement / Physics Reimagined, Laboratoire de Physique des Solides / Laboratory of Solid state Physics, Université Paris-Saclay / Paris-Saclay University

This work is based on the phyphox Arduino library developed by the phyphox team at the RWTH Aachen University, which is released under the GNU Lesser General Public Licence v3.0 (or newer).
This work is released under the GNU Lesser General Public Licence v3.0 (or newer).
 */

#include <phyphoxBle.h> 
#include <Arduino_LSM9DS1.h>


char board_name[] = "nano_33_ble"; // to change the name displayed by the board using BLE: no space and no special character
float choice = 0.0;
float accx, accy, accz, acc;
float gyrx, gyry, gyrz, gyr;
float magx, magy, magz, magn;
int red, green, blue, ambient;
float red_float, green_float, blue_float, ambient_float;
unsigned long initial_time, first_time;
float first_difference_float;
unsigned int period = 50;
const int ledPin = 22;
const int ledPin2 = 23;
const int ledPin3 = 24;

void receivedData(); // see Phyphox Arduino Library example

void setup()
{   
   PhyphoxBLE::minConInterval = 6; //6 = 7.5ms
   PhyphoxBLE::maxConInterval = 6; //6 = 7.5ms
   PhyphoxBLE::slaveLatency = 0; //
   PhyphoxBLE::timeout = 10; //10 = 100ms

   pinMode(22, OUTPUT);
   pinMode(23, OUTPUT);
   pinMode(24, OUTPUT);

   digitalWrite(ledPin, LOW);
   digitalWrite(ledPin2, HIGH);
   digitalWrite(ledPin3, HIGH);
   
   if (!IMU.begin()) { // starting all useful sensors
     while (1);
   }

   PhyphoxBLE::start("nano_ble"); // the name of the board can be changed at the beginning of the program
   PhyphoxBLE::configHandler=&receivedData; // see Phyphox Arduino library example
}

void loop() // depending on the config parameter sent by Phyphox, an experiment is chosen
{
   if (PhyphoxBLE::currentConnections > 0){
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
   }else{
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
   }
   
   if(choice == 1.0){
      accelerometerChoice();
   }else if(choice == 2.0){
      gyroscopeChoice();
   }else if(choice == 3.0){
      magnetometerChoice();

   }else{
   }
}

void receivedData(){ // see Phyphox Arduino Library example
   if (PhyphoxBLE::currentConnections == 1){
      PhyphoxBLE::read(choice); // the "choice" variable is written by our Phyphox experiments
      initial_time = millis();
   }
}

void accelerometerChoice() { // if the sensor is available, the acceleration and a timestamp are written to the BLE server, and then to the Phyphox app
    if (IMU.accelerationAvailable()) {
      first_time = millis();
      IMU.readAcceleration(accx, accy, accz);
      first_difference_float = ((float)first_time-(float)initial_time)/1000;
      acc = sqrt(pow(accx, 2) + pow(accy, 2) + pow(accz, 2));
      PhyphoxBLE::write(first_difference_float, accx, accy, accz, acc);
    }
}

void gyroscopeChoice() {
    if (IMU.gyroscopeAvailable()) {
      first_time = millis();
      IMU.readGyroscope(gyrx, gyry, gyrz);
      first_difference_float = ((float)first_time-(float)initial_time)/1000;
      gyr = sqrt(pow(gyrx, 2) + pow(gyry, 2) + pow(gyrz, 2));
      PhyphoxBLE::write(first_difference_float, gyrx, gyry, gyrz, gyr);
    }
}

void magnetometerChoice() {
    if (IMU.magneticFieldAvailable()) {
      first_time = millis();
      IMU.readMagneticField(magx, magy, magz);
      first_difference_float = ((float)first_time-(float)initial_time)/1000;
      magn = sqrt(pow(magx, 2) + pow (magy, 2) + pow(magz, 2));
      PhyphoxBLE::write(first_difference_float, magx, magy, magz, magn);
    }
}
