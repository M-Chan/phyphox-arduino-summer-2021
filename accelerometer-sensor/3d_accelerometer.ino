/*
This program should plot graphs of the acceleration in one view
The graphs should have discrete points
*/

#include <phyphoxBle.h>
#include <Arduino_LSM9DS1.h>

void setup() {
  // put your setup code here, to run once:
  PhyphoxBLE::start();

  PhyphoxBleExperiment tdAccelerometerExp; //This is to generate my 3d accelerometer experiment
  tdAccelerometerExp.setTitle("3D Acceleration");
  tdAccelerometerExp.setCategory("Phyphox Arduino Experiments");

  PhyphoxBleExperiment::Graph xGraph; //Creates the graph
  xGraph.setLabel("X Acceleration Graph");
  xGraph.setLabelX("Time");
  xGraph.setUnitX("s");
  xGraph.setLabelY("X Acceleration");
  xGraph.setUnitY("");
  xGraph.setStyle("dots"); //Makes each data point a dot
  xGraph.setChannel(0,1); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::Graph yGraph; //Creates the graph
  yGraph.setLabel("Y Acceleration Graph");
  yGraph.setLabelX("Time");
  yGraph.setUnitX("s");
  yGraph.setLabelY("Y Acceleration");
  yGraph.setUnitY("");
  yGraph.setStyle("dots"); //Makes each data point a dot
  yGraph.setChannel(0,2); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::Graph zGraph; //Creates the graph
  zGraph.setLabel("Z Acceleration Graph");
  zGraph.setLabelX("Time");
  zGraph.setUnitX("s");
  zGraph.setLabelY("Z Acceleration");
  zGraph.setUnitY("");
  zGraph.setStyle("dots"); //Makes each data point a dot
  zGraph.setChannel(0,3); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::View graphsView; //Creates a view
  graphsView.setLabel("3D Acceleration Graphs");
  graphsView.addElement(xGraph); //Adds the graph to this view
  graphsView.addElement(yGraph); //Adds the graph to this view
  graphsView.addElement(zGraph); //Adds the graph to this view

  tdAccelerometerExp.addView(graphsView); //Adds the view to the experiment
  PhyphoxBLE::addExperiment(tdAccelerometerExp); //Attaches this experiment to the server for writing the data to the Arduino

  if (!IMU.begin()) {
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    
  float x, y,z;
  
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }
  
  PhyphoxBLE::write(x,y,z);
  
  delay(1000);
}
