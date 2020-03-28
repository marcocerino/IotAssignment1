import MQTTSNclient as mqttsn
import Queue as q
import time
import mqtt_client as mqtt

ACCESS_TOKEN='67v7kSViFKVYDccBawvd'                						#Token of the device
broker="demo.thingsboard.io"   			    							#host name
port=1883 					    										#data listening port

print("connecting to the online MQTT broker")
mclient = mqtt.MQTT_client(ACCESS_TOKEN,broker,port)

class MyCallback:														
	def messageArrived(self, topicName, payload, qos, retained, msgid):		#callback function on message arrival
	 print "default publishArrived"
	 ret= mclient.publish(payload) 			
	 return True


aclient = mqttsn.Client("linh", port=1885)
aclient.registerCallback(MyCallback())
aclient.connect()
aclient.subscribe("v1/devices/me/telemetry")


try:
	while(1):
		time.sleep(2)
except KeyboardInterrupt:
	print("Closing the client")
	aclient.disconnect()
	mclient.disconnect()


