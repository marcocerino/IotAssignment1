# IotAssignment

This directory contains my delivery for the assignments for the 2020 IOT course for the  Engineering in Computer Science master degree at Sapienza University of Roma.

valueGenerator  directory contains a program that randomly generate values and publish them to a cloud-based MQTT broker

randomMQTTSNbridge contains an application that thatnks to a RIOT application generate random values and publish them to a RSMB MQTT-SN broaker, and then publish them on a web interface thanks to a python program that implements a MQTT-SN to MQTT bridge. 


The web interface where are the generated data are published is:
https://demo.thingsboard.io/dashboard/6f0c9740-6a9c-11ea-8e0a-7d0ef2a682d3?publicId=d2ff5950-6a96-11ea-8e0a-7d0ef2a682d3
