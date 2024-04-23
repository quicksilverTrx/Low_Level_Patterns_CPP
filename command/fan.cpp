using namespace std;
#include <iostream>
class CeilingFan
{
    public:
    enum class Speed
    {
        OFF,
        LOW,
        MEDIUM,
        HIGH
    };
    Speed currentSpeed;

    CeilingFan(): currentSpeed(Speed::OFF){}

    void high()
    {
        currentSpeed=Speed::HIGH;
        cout<<"Fan Speed is high"<<endl;
    }

    void low()
    {
        currentSpeed=Speed::LOW;
        cout<<"Fan Speed is low"<<endl;
    }

    void mid()
    {
        currentSpeed=Speed::MEDIUM;
        cout<<"Fan Speed is medium"<<endl;
    }

    void off()
    {
        currentSpeed=Speed::OFF;
        cout<<"Fan Speed is switched off"<<endl;
    }

    Speed getSpeed()
    {
        return this->currentSpeed;
    }    
};