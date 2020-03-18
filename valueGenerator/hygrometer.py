from numpy.random import randint
#Hygrometer get us the humidity
class Hygrometer(object):
	"""docstring for Hygrometer"""
	def __init__(self):
		super(Hygrometer, self).__init__()

	def getHumidity(self):
		return randint(0,100,1)
