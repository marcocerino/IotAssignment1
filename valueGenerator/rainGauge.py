from numpy.random import randint
#rain gauge gets us rain height
class RainGauge(object):
	"""docstring for RainGauge"""
	def __init__(self):
		super(RainGauge, self).__init__()

	def getRain(self):
		return str(randint(0,50,1)[0])