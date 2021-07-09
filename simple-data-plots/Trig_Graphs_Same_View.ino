/*
This program should plot a trig graphs in one view
The graphs should have discrete points
*/


#include <phyphoxBle.h>

void setup() {
  PhyphoxBLE::start();

  PhyphoxBleExperiment trigGraphsExp; //This is to generate my trig graph plotting experiment
  trigGraphsExp.setTitle("Trig Graph Plotter");
  trigGraphsExp.setCategory("Phyphox Arduino Experiments");

  PhyphoxBleExperiment::Graph sineGraph; //Creates the sine graph
  sineGraph.setLabel("Sine Graph");
  sineGraph.setLabelX("Angle");
  sineGraph.setUnitX("rads");
  sineGraph.setLabelY("Sin(Angle)");
  sineGraph.setUnitY("");
  sineGraph.setStyle("dots"); //Makes each data point a dot
  sineGraph.setChannel(1,2); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::Graph cosineGraph; //Creates the cosine graph
  cosineGraph.setLabel("Cosine Graph");
  cosineGraph.setLabelX("Angle");
  cosineGraph.setUnitX("rads");
  cosineGraph.setLabelY("Cos(Angle)");
  cosineGraph.setUnitY("");
  cosineGraph.setStyle("dots"); //Makes each data point a dot
  cosineGraph.setChannel(1,3); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::Graph tanGraph; //Creates the tan graph
  tanGraph.setLabel("Tan Graph");
  tanGraph.setLabelX("Angle");
  tanGraph.setUnitX("rads");
  tanGraph.setLabelY("Tan(Angle)");
  tanGraph.setUnitY("");
  tanGraph.setStyle("dots"); //Makes each data point a dot
  tanGraph.setChannel(1,4); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::View trigView; //Creates a view
  trigView.setLabel("Trig Graphs");
  trigView.addElement(sineGraph); //Adds the graph to this view
  trigView.addElement(cosineGraph); //Adds the graph to this view
  trigView.addElement(tanGraph); //Adds the graph to this view

  trigGraphsExp.addView(trigView); //Adds the view to the experiment
  PhyphoxBLE::addExperiment(trigGraphsExp); //Attaches this experiment to the server for writing the data to the Arduino
  
}

void loop() {
    for (float i = -360; i <= 360; i += 1){ //only allows angles between -360 and 360 degrees to be plotted
    float y1 = sin((i*PI)/180); //calculates sin(angle in rads)
    float y2 = cos((i*PI)/180); //calculates cos(angle in rads)
    float y3 = tan((i*PI)/180); //calculates tan(angle in rads)
    float x = (i*PI)/180; //converts angle from degrees to radians
    PhyphoxBLE::write(x,y1,y2,y3);    //writes the angles and trig values to phyphox to plot in the trig graph made
    delay(100);                  //Tenth of a second pause before next data point
    }
}
