// #ifndef observable_include
// #define observable_include
#pragma once
//#include "observable.cpp"
#include "iostream"
class Observer;
using namespace std;
class Observable
{
    public:
    virtual void registerObserver(Observer *observer) =0;
    virtual void removeObserver(Observer *observer) =0;
    virtual void notifyObserver()=0;
};
class WeatherData : public Observable
{
    public:
        vector<Observer*> observerList;
        double temp,pressure,humidity;
        WeatherData() {}
        void  registerObserver(Observer *observer) override
        {
            observerList.push_back(observer);
        }

        void notifyObserver() override;
        void removeObserver(Observer *observer)
        {
            auto it = std::find(obser)
        }
        void measurementsChanged()
        {
            this->notifyObserver();
        }

        void setMeasurements(double temp,double humidity,double pressure)
        {
            this->temp=temp;
            this->pressure=pressure;
            this->humidity=humidity;
            this->measurementsChanged();
        }
};



class Observer
{
    public:
    virtual ~Observer(){}
    virtual void update(double temp,double pressure,double humidity)=0;
};
class DisplayElement
{
    public:
    virtual void display()=0;
};
class CurrentConditionsDisplay: public DisplayElement,public Observer
{
    public:
        Observable *observable;
        double temp,pressure,humidity;
        CurrentConditionsDisplay(){}
        CurrentConditionsDisplay(Observable *observable): observable(observable) { observable->registerObserver(this);}

        void update(double temp,double pressure,double humidity) override
        {
            this->temp=temp;
            this->pressure=pressure;
            this->humidity=humidity;
            display();
        }

        void display() override
        {
            // Display current conditions.
            std::cout << "=================================" << std::endl;
            std::cout << "Current Conditions --------------" << std::endl;
            std::cout << "Temperature : " << temp << std::endl;
            std::cout << "Humidity : " << humidity << std::endl;
            std::cout << "Pressure : " << pressure << std::endl;
            std::cout << std::endl;
        }
};

class ForecastDisplay : public DisplayElement,public Observer
{
    public:
        Observable *observable;
        double temp,pressure,humidity;
        ForecastDisplay(){}
        ForecastDisplay(Observable *observable) : observable(observable) {observable->registerObserver(this);}

        void update(double temp,double pressure,double humidity) override
        {
            this->temp=temp;
            this->pressure=pressure;
            this->humidity=humidity;
            display();
        }

        void display() override
        {
            // Display current conditions.
            std::cout << "=================================" << std::endl;
            std::cout << "Forecast Conditions --------------" << std::endl;
            std::cout << "Temperature : " << temp << std::endl;
            std::cout << "Humidity : " << humidity << std::endl;
            std::cout << "Pressure : " << pressure << std::endl;
            std::cout << std::endl;
        }


};
void WeatherData:: notifyObserver() 
{
    for (Observer* observer: WeatherData::observerList)
    {
        observer->update(WeatherData::temp,WeatherData::pressure,WeatherData::humidity);
    }
}
// #endif