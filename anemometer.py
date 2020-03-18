from numpy.random import randint
#anenometer gets us wind direction and intensity
class Anemometer(object):
	"""docstring for Anemometer"""
	def __init__(self):
		super(Anemometer, self).__init__()
		
	def getWindDirection(self):
		return randint(0,360,1)

	def getWindIntensity(self):
		return randint(0,100,1)
