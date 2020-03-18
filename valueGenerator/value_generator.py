from anemometer import Anemometer
from hygrometer import Hygrometer
from rainGauge import RainGauge
from thermometer import Thermometer


anomometer=Anemometer()
hygrometer=Hygrometer()
rain_gauge=RainGauge()
thermometer=Thermometer()

while(1):
	temperature = thermometer.getTemperature()
	humidity = hygrometer.getHumidity()
	rain = rain_gauge.getRain()
	wind_dir = anomometer.getWindDirection()
	wind_int = anomometer.getWindIntensity()
	print("temperature: " + str(temperature))
	print("humidity: "+ str(humidity))
	print("rain: "+ str(rain))
	print("wind_dir: "+ str(wind_dir))
	print("wind_int: "+ str(temperature))
	sleep(5)