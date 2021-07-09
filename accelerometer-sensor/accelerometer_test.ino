/*
Test to access the Arduino's accelerometer
*/

#include <phyphoxBle.h>
#include <Arduino_LSM9DS1.h>


void setup() {
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

  if (!IMU.begin()) {
    while (1); //terminates program if sensors aren't found
  }
}

void loop() {
  float x, y,z;
  
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z); //reads sensor data
  }
  
  x = 100*x;

  PhyphoxBLE::write(x,y,z); //writes to server
  delay(1000); //delays by 1 second
}
