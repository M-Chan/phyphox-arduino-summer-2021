# Visualising Remote Sensor Data on a Mobile Phone
Arduino .ino files and .phyphox files (basically XML) I created during my 2021 summer Physics internship

## Acknowledgements
A lot of this code has been modified from the original phyphox app experiments using their open source .phyphox files
These are available from this github: https://github.com/phyphox/phyphox-experiments
For the .ino files, some of it was based on files from https://github.com/phyphox/phyphox-arduino

The .ino file for allowing Phyphox to access the IMU sensor data was modified from https://hebergement.universite-paris-saclay.fr/phyphox/nano_phyphox_v1.ino

Many thanks to my supervisor Dr Davies for guiding me through this project


## Folders and Files
The 'simple-data-plots' folder is me testing how to write .ino files that allows data to be transfered from the Arduino Nano to the Phyphox app

The 'accelerometer-sensor' folder has .ino files and is me testing how to access the sensor on an Arduino Nano

The 'imu-statistics-phyphox-files' folder has .phyphox files for the accelerometer, gyroscope and magnetometer. Each file plots graphs of each axial component variable w.r.t. time and a histogram showing the count distribution with a fitted Gaussian curve. It also includes the .ino file to upload to the Arduino Nano allowing for the data transfer.

The 'forced-oscillator-experiment' has the.phyphox files for retrieving the data from this experiment. The ocillator-exp.phyphox file just has the acceleration w.r.t. time graph and the FFT graph; no resonance curve added. (Note you will need the .ino file in the above folder to access the accelerometer). The resonance-attempt file is me trying to add a resonance curve and after trying many different things this is the last try - still not a resonance curve in the end but maybe the code would be of use.



## Screenshots
For the trig graphs on the same view...
![trig graphs (same view)](https://user-images.githubusercontent.com/81781462/123165714-7df9a000-d46c-11eb-8cee-c6439fbced72.jpg)

For the 3d accelerometer data plot...
![3D accelerometer](https://user-images.githubusercontent.com/81781462/124750684-ad54e600-df1d-11eb-8fa6-12b7c9b51826.jpg)

For one of the imu-statistics (magnetometer)...
![magnetometer_view1](https://user-images.githubusercontent.com/81781462/124754027-9ca66f00-df21-11eb-8608-c91ac305c41c.jpeg)

