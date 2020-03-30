import MQTTSNclient as mqttsn
import Queue as q
import time
import mqtt_client as mqtt
	    										

#connect to the MQTT ThingsBoard broker
print("connecting to the online MQTT broker")
mclient = mqtt.MQTT_client()

#define callback class for MQTT-SN client
class MyCallback:								
	#callback function for a message arrival:
		#it pubs the payload of the received messages to the MQTT broker

	def messageArrived(self, topicName, payload, qos, retained, msgid):		
	 print "default publishArrived"
	 ret= mclient.publish(payload) 			
	 return True

mqttsn_ip = input("Type the broaker IPv6 addess: ");

print("connecting to the MQTT-SN broker")
#create MQTT-SN client and connect to RSMB
aclient = mqttsn.Client("linh",host=mqttsn_ip, port=1885)
aclient.registerCallback(MyCallback())
aclient.connect()
#subscribe the client to the topic the RIOT app pubs on
aclient.subscribe("v1/devices/me/telemetry")

#infinite loop fo rthe MQTT-SN client 
try:
	while(1):
		time.sleep(2)
except KeyboardInterrupt:
	print("Closing the client")
	aclient.disconnect()
	mclient.disconnect()


