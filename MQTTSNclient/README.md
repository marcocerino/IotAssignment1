#About

This directory contains the MQTT-SN to MQTT bridge so that the values published  RIOT application in the RIOT_pub directory can be shown on the  web interface I've implemented.
In order to implement such a bridge I've created a Python program that implements both an MQTT-SN client ,that can connect to the broker and subscibe to the topic the values are published on (v1/devices/me/telemetry), and an MQTT client that could publish the received data on the cloud broker.

#MQTT-SN client

To implement the MQTT-SN client, I've used the library provided in the eclipse/mosquito.rsmb example. This library consist of the files MQTTSN.py, MQTTSNclient.py, MQTTSNinternal.py, MQTTSNregister.py that are in this direcory.
To download rsmb:
git clone https://github.com/eclipse/mosquitto.rsmb.git
The library can be found in the directory /mosquitto.rsmb/rsmb/src/MQTTSNclient/Python

#MQTT client

The MQTT client implementation can be found in the file mqtt_client.py.
To run such a file, the paho.mqtt library is required.
To install it: pip install paho
To read more about it: https://pypi.org/project/paho-mqtt/
This program creates a client that connect directly to the my cloud-based MQTT broker, and publish the data on topic v1/devices/me/telemetry, so that these values can be shown in the web interface I've implemented.