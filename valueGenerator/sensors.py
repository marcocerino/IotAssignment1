#import the sensors
from anemometer import Anemometer
from hygrometer import Hygrometer
from rainGauge import RainGauge
from thermometer import Thermometer

class Sensors(object):
	"""docstring for Sensors"""
	def __init__(self,):
		super(Sensors, self).__init__()
		#create the sensore
		self.anomometer=Anemometer()
		self.hygrometer=Hygrometer()
		self.rain_gauge=RainGauge()
		self.thermometer=Thermometer()


	def getValue(self):
		temp = thermometer.getTemperature();
		hum = hygrometer.getHumidity()
		wind_dir = anomometer.getWindDirection()
		wind_int = anomometer.getWindIntensity()
		rain = rain_gauge.getRain()
		return temp,hum,wind_dir,wind_int,rain

