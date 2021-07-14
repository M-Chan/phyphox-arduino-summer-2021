/*
This program should plot trig graphs in separate tab views
The graph should have discrete points
*/


#include <phyphoxBle.h>

void setup() {
  // put your setup code here, to run once:
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

  PhyphoxBleExperiment::View firstView; //Creates the sine graph view
  firstView.setLabel("Sine");
  firstView.addElement(sineGraph); //Adds the sine graph to this view


  PhyphoxBleExperiment::Graph cosineGraph; //Creates the cosine graph
  cosineGraph.setLabel("Cosine Graph");
  cosineGraph.setLabelX("Angle");
  cosineGraph.setUnitX("rads");
  cosineGraph.setLabelY("Cos(Angle)");
  cosineGraph.setUnitY("");
  cosineGraph.setStyle("dots"); //Makes each data point a dot
  cosineGraph.setChannel(1,3); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::View midView; //Creates the cosine graph view
  midView.setLabel("Cosine");
  midView.addElement(cosineGraph); //Adds the cosine graph to this view


  PhyphoxBleExperiment::Graph tanGraph; //Creates the tan graph
  tanGraph.setLabel("Tan Graph");
  tanGraph.setLabelX("Angle");
  tanGraph.setUnitX("rads");
  tanGraph.setLabelY("Tan(Angle)");
  tanGraph.setUnitY("");
  tanGraph.setStyle("dots"); //Makes each data point a dot
  tanGraph.setChannel(1,4); //Plots x and y from paramaters in the server (write - later in the loop) 

  PhyphoxBleExperiment::View lastView; //Creates the tan graph view
  lastView.setLabel("Tan");
  lastView.addElement(tanGraph); //Adds the tan graph to this view


  trigGraphsExp.addView(firstView); //Adds the sine graph view to the experiment
  trigGraphsExp.addView(midView); //Adds the cosine graph view to the experiment
  trigGraphsExp.addView(lastView); //Adds the tan graph view to the experiment
  PhyphoxBLE::addExperiment(trigGraphsExp); //Attaches this experiment to the server for writing the data to the Arduino
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
    for (float i = -360; i <= 360; i += 1){
    float y1 = sin((i*PI)/180);
    float y2 = cos((i*PI)/180);
    float y3 = tan((i*PI)/180);
    float x = (i*PI)/180;
    PhyphoxBLE::write(x,y1,y2,y3);    //Sends random values to phyphox to plot in the trig graph made
    delay(100);                  //Tenth of a second pause before next data point
    }
}
