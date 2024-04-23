#include "command.cpp"
#include <iostream>
int main()
{
    Light light;
    LightOnCommand lightOnCommand(&light); 
    LightOffCommand lightOffCommand(&light); 
    CeilingFan ceilingFan;
    CeilingFanHighSpeedCommand fanHighSpeedCommand(ceilingFan);
    lightOnCommand.execute();
    lightOffCommand.execute();
    fanHighSpeedCommand.execute();
    fanHighSpeedCommand.undo();
}