import MQTTSNclient as mqttsn
import Queue as q
import time

msg_queue = q.Queue()
class MyCallback:
	def messageArrived(self, topicName, payload, qos, retained, msgid):
	 m= "d-p-Arrived" +" topic  " +str(TopicId)+ "message " +\
	 str(payload) +"  qos= " +str(qos) +" ret= " +str(retained)\
	 +"  msgid= " + str(msgid)
	 print("got the message ",payload)
	 msg_queue.put(payload)
	 return True

def empty_queue():
   while not msg_queue.empty():
      m=msg_queue.get()
      print("Received message  ",m)

aclient = mqttsn.Client("linh", port=1885)
aclient.registerCallback(mqttsn.Callback())
aclient.connect()


aclient.subscribe("v1/devices/me/telemetry")
try:
	while(1):
		time.sleep(2)
		empty_queue()
except KeyboardInterrupt:
	print("Closing the client")
	aclient.disconnect()


