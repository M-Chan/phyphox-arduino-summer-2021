/*
Test to access the Arduino's accelerometer
*/
#include <phyphoxBle.h>
#include <Arduino_LSM9DS1.h>

//float x, y, z;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
 
  
  PhyphoxBLE::start();

  PhyphoxBleExperiment accelerometerExp; //This is to generate my experiment
  accelerometerExp.setTitle("Accelerometer Test");
  accelerometerExp.setCategory("Phyphox Arduino Experiments");

  PhyphoxBleExperiment::Graph accelerometerGraph; //Creates the graph
  accelerometerGraph.setLabel("Accelerometer");
  accelerometerGraph.setLabelX("Time");
  accelerometerGraph.setUnitX("s");
  accelerometerGraph.setLabelY("X-accelerometer");
  accelerometerGraph.setUnitY("");
  accelerometerGraph.setStyle("dots"); //Makes each data point a dot
  accelerometerGraph.setChannel(0,1); //Plots x accelerometer over time from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::View firstView; //Creates a view
  firstView.setLabel("Accelerometer");
  firstView.addElement(accelerometerGraph); //Adds the graph to this view

  accelerometerExp.addView(firstView); //Adds the view to the experiment
  PhyphoxBLE::addExperiment(accelerometerExp); //Attaches this experiment to the server for writing the data to the Arduino
}

void loop() {
  // put your main code here, to run repeatedly:

  float x, y,z;
  
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }
  x = 100*x;
  float degreesX = map(x, 0, -100, 0, 90);
  Serial.print(degreesX);
  PhyphoxBLE::write(x,y,z);
  delay(1000);
}
