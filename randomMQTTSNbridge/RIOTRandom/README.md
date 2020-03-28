#About

This directory contains a Riot application that can connect to a local MQTT-SN broker, in particular rsmb, and publish randomly generated values.

##RSMB Setup

1. You will need to install rsmb. It can be cloned from a git repository
git clone https://github.com/eclipse/mosquitto.rsmb.git

2. You need to compile rsmb; so go to the  cloned directory and then
'''javascript
cd mosquitto.rsmb/rsmb/src
make
'''

3. You will need a configuration file for the broker. The one I used for this application is in this directory as config.conf.
You can just copy this file into the broker directory

4. You can now run the broker
./broker_mqtts config.conf

##Setting up RIOT

1. Before you can run the application, you will need to create the interface through which it can communicate with the broker. You can use the RIOT's tapsetup tool. If you want to run multiple application, you will need to replicate this passages in order to build the different interfaces

sudo ./RIOTDIR/dist/tools/tapsetup/tapsetup

2. Assign a site-global prefix to the tapbr0 interface
sudo ip a a fec0:affe::1/64 dev tapbr0

3. Now you can run the application
cd /path/to/this/directory
make all term

4. You need to assign a site-global address with the same address within the RIOT instance
ifconfig 5 add fec0:affe::99


##USAGE

1. Now we can communicate with the broker, so firstly we connect to it
con fec0:affe::1 1885
The port number can change if you modify your broker's configuration file

2. To start publishing the randomly generated values, just execute the following command
pub_values
The values will be published on the v1/devices/me/telemetry topic. 
A message will have the form: 
"{\"Temperature\":%d,\"Humidity\":%d,\"WindDirection\":%d,\"WindIntensity\":%d,\"RainHight\":%d}"