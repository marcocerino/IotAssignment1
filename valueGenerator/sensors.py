#import the sensors
from anemometer import Anemometer
from hygrometer import Hygrometer
from rainGauge import RainGauge
from thermometer import Thermometer

class Sensors(object):
	"""docstring for Sensors"""
	def __init__(self):
		super(Sensors, self).__init__()
		#create the sensore
		self.anemometer=Anemometer()
		self.hygrometer=Hygrometer()
		self.rain_gauge=RainGauge()
		self.thermometer=Thermometer()


	def getValue(self):
		temp = self.thermometer.getTemperature();
		hum = self.hygrometer.getHumidity()
		wind_dir = self.anemometer.getWindDirection()
		wind_int = self.anemometer.getWindIntensity()
		rain = self.rain_gauge.getRain()
		return temp,hum,wind_dir,wind_int,rain

