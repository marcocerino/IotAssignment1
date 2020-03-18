from time import sleep
#import the client
import paho.mqtt.client as mqtt
#import the sensors
from sensors import Sensors

##################################################
#message callback function
def on_message(client,userdata,message):
	if message.topic = "getValue":
		s = Sensors()
		values = s.getValue()
		client.publish("thermometer/temperature",str(values[0]))
		client.publish("hygrometer/humidity",str(values[1]))
		client.publish("anomometer/wind_dir",str(values[2]))
		client.publish("anomometer/wind_int",str(values[3]))
		client.publish("rain_gauge/rain",str(values[4]))

#####################################

#broker_address
#broaker_port

#client_name

#create mqtt client
	#client = mqtt.Client(client_name)

#connect client to host
	#client.connect(broker_address,braker_port)

#subscribe to new info
	#client.subscribe("getValue")

#attach function to execute at msg recieve
	#clien.on_message=on_message

#client.loop_forever()
