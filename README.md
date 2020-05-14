# IotAssignment

This directory contains my delivery for the assignments for the 2020 IOT course for the  Engineering in Computer Science master degree at Sapienza University of Roma.

## valueGenerator  
This directory contains a program that randomly generate values and publish them to a cloud-based MQTT broker

##randomMQTTSNbridge 
It contains an application that thanks to a RIOT application generate random values and publish them to a RSMB MQTT-SN broker, and then publish them on a web interface thanks to a python program that implements a MQTT-SN to MQTT bridge. 

##LoRaWan
In the LoRaWan directory, the MQTT protocol was changed with LoRaWan. It contains a Riot app, that should run on the IoT-Lab's boards, and a python bridge, that connects the app to the ThingsBoard dashboard used in the other directories

##crowdSensing
In the crowdSensing directory is the source code for a web app that test crowd sensing potentiality having a Human Activity Recognition model based on data from the user's smartphone's accelerometer sensor deployed both in a cloud-based and in a edge-based architecture.

To see more detail on each project, each directory has its own README file.

