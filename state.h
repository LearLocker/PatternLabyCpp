#ifndef STATE_H
#define STATE_H
#include <iostream>

class Heater;

class State
{
     std::string name;
public:
    State(const std::string& name): name(name) {}

    std::string GetName()
    {
        return name;
    }

    virtual void TurnOff(Heater*) = 0;
    virtual void TurnOn(Heater*) = 0;
};

class PowerOffState : public State
{
public:
    PowerOffState() : State("PowerOff"){}
    ~PowerOffState();

        void TurnOn(Heater* device);
        void TurnOff(Heater* device);
};


class Heater
{
public:
    Heater(int _id, State *_state);
    ~Heater();

    bool GetCurrentState();

    void setId(int id);

    int getId();

    void TurnOn();

    void TurnOff();

    void ChangeState(State *newState);

    void setMessage(std::string msg);

    State* GetState();

private:
    State* state;
    bool _CurrentState;
    int id;
    std::string message;
};



class PowerOnState : public State
{
public:
    PowerOnState(): State("PowerOn"){}
    ~PowerOnState();

    void TurnOff(Heater* device);
    void TurnOn(Heater* device);

};

#endif // STATE_H
