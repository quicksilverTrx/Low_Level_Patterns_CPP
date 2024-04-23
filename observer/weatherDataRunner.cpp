//#include "observable.cpp"
#include "observer.cpp"
#include <vector>

int main()
{
    WeatherData weatherData;
    CurrentConditionsDisplay currentConditionsDisplay(&weatherData) ;
    ForecastDisplay forecastDisplay(&weatherData);
    weatherData.setMeasurements(27.6,10.0,8.9);
    weatherData.setMeasurements(31.2, 9.5, 11.2);
}