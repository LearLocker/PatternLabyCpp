#ifndef COMMAND_H
#define COMMAND_H

#include "light.h"

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
};

// Command for turning on the Light
class LightOnCommand : public Command
{
public:
        LightOnCommand(Light *light) : mLight(light) {}
    void execute(){
        mLight->on();
    }
private:
    Light *mLight;
};

// Command for turning off the light
class LightOffCommand : public Command
{
public:
        LightOffCommand(Light *light) : mLight(light) {}
    void execute(){
        mLight->off();
    }
private:
    Light *mLight;
};

#endif // COMMAND_H
