# Visualising Remote Sensor Data on a Mobile Phone
Arduino .ino files and .phyphox files (basically XML) I created during my 2021 summer Physics internship

## Acknowledgements
A lot of this code has been modified from the original phyphox app experiments using their open source .phyphox files
These are available from this github: https://github.com/phyphox/phyphox-experiments
For the .ino files, some of it was based on files from https://github.com/phyphox/phyphox-arduino

The .ino file for allowing Phyphox to access the IMU sensor data was modified from https://hebergement.universite-paris-saclay.fr/phyphox/nano_phyphox_v1.ino

Special thanks to my supervisor Dr Davies for providing me with this project and guiding me throughout. Many thanks to Dr Cubiss for providing suggestions for contructing a resonance curve manually.


## Folders and Files
The 'simple-data-plots' folder is me testing how to write .ino files that allows data to be transfered from the Arduino Nano to the Phyphox app

The 'accelerometer-sensor' folder has .ino files and is me testing how to access the sensor on an Arduino Nano

The 'imu-statistics-phyphox-files' folder has .phyphox files for the accelerometer, gyroscope and magnetometer. Each file plots graphs of each axial component variable w.r.t. time and a histogram showing the count distribution with a fitted Gaussian curve. It also includes the .ino file to upload to the Arduino Nano allowing for the data transfer.

The 'forced-oscillator-experiment' has the.phyphox files for retrieving the data from this experiment. The ocillator-exp.phyphox file just has the acceleration w.r.t. time graph and the FFT graph; no resonance curve added. (Note you will need the .ino file in the above folder to access the accelerometer). I have tried to add a resonance curve and this folder includes some of the attempts I have made - still not a resonance curve in the end but the code might still be of use. 
**Note: you can find the resonance frequency using the FFT graph and reading the peak frequency after setting the Arduino oscillating without the vibration generator.**
**Note: the resonance attempts are not in order (last attempt is not necessarily the best).**
**Note: if for resonance-attempt-3.phyphox the curve is levelling off, you just need to reset the data.**


## Screenshots
For the trig graphs on the same view...
![trig graphs (same view)](https://user-images.githubusercontent.com/81781462/123165714-7df9a000-d46c-11eb-8cee-c6439fbced72.jpg)

For the 3d accelerometer data plot...
![3D accelerometer](https://user-images.githubusercontent.com/81781462/124750684-ad54e600-df1d-11eb-8fa6-12b7c9b51826.jpg)

For one of the imu-statistics (magnetometer)...
![magnetometer_view1](https://user-images.githubusercontent.com/81781462/124754027-9ca66f00-df21-11eb-8608-c91ac305c41c.jpeg)

Oscillator Experiment without Resonance Curve (Vibration generator turned off)...
![osc_exp](https://user-images.githubusercontent.com/81781462/125617892-4b406df2-ddb7-4f4b-9720-8567d20e7f32.jpeg)


Resonance Attempt 1...
![Res1-2](https://user-images.githubusercontent.com/81781462/125280003-7cedbd00-e30c-11eb-8787-9bde457dbb36.jpeg)

Resonance Attempt 2...
![res2](https://user-images.githubusercontent.com/81781462/125272020-43fd1a80-e303-11eb-8dd6-5f8726381590.jpeg)


Resonance Attempt 3...

![res3-1](https://user-images.githubusercontent.com/81781462/125291330-2c309100-e319-11eb-96e5-b4dc2878ae9c.png)
![Res3-2](https://user-images.githubusercontent.com/81781462/125291341-2f2b8180-e319-11eb-96c2-06b6422ee2d4.jpeg)

Resonance Attempt 4...
**Note: Unlike the other attempts, this one requires changing the driving frequency to produce a resonance graph**
![Res4](https://user-images.githubusercontent.com/81781462/125617753-2249a2de-de47-4595-947a-25b39ce7c0a4.jpeg)


## Manually Produced Resonance Curves
