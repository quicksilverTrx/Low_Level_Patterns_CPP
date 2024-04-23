using namespace std;
#include "light.cpp"
#include "fan.cpp"
class Command
{
    public:
    virtual void execute()=0;
    virtual void undo() =0;
};

class LightOnCommand : public Command
{
    public:
    Light *light;
    LightOnCommand(Light *light) : light(light){}

    void execute() override
    {
        light->on();
    }
    
    void undo() override
    {
        light->off();
    }
};

class LightOffCommand : public Command
{
    public:
    Light *light;
    LightOffCommand(Light *light) : light(light){}

    void execute() override
    {
        light->off();
    }
    
    void undo() override
    {
        light->off();
    }
};
class  CeilingFanHighSpeedCommand : public Command
{
    public:
    CeilingFan ceilingFan;
    CeilingFan::Speed previousSpeed;
    CeilingFanHighSpeedCommand(CeilingFan &ceilingFan): ceilingFan(ceilingFan) {previousSpeed = ceilingFan.getSpeed();}

    void execute() override
    {
        previousSpeed = ceilingFan.getSpeed();
        ceilingFan.high();
        
    }
    void undo() override
    {
        switch (previousSpeed)
        {
            case (CeilingFan::Speed::HIGH):
            {
                ceilingFan.high();
                break;
            }
            case (CeilingFan::Speed::MEDIUM):
            {
                ceilingFan.mid();
                break;
            }
            case (CeilingFan::Speed::LOW):
            {
                ceilingFan.low();
                break;
            }
            case (CeilingFan::Speed::OFF):
            {
                ceilingFan.off();
                break;
            }
        }
    }
};