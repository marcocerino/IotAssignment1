from numpy.random import randint
class Thermometer(object):
	"""docstring for Thermometer"""
	def __init__(self):
		super(Thermometer, self).__init__()
		
	def getTemperature(self):
		return randint(-50,50,1)
