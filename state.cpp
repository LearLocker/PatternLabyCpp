#include "state.h"

Heater::Heater(int _id, State *_state) : state(_state)
{ setId(_id);_CurrentState = false;}

Heater::~Heater()
{
    delete state;
}

bool Heater::GetCurrentState()
{
    return _CurrentState;
}

void Heater::setId(int id) { this->id = id; }

int Heater::getId(){ return id;}

void Heater::TurnOn()
{
    _CurrentState = true;
    state->TurnOn(this);
}

void Heater::TurnOff()
{
    _CurrentState = false;
    state->TurnOff(this);
}

void Heater::ChangeState(State *newState) {
    state = newState;
}

void Heater::setMessage(std::string msg){
    message = msg;
}

State *Heater::GetState()
{
    return state;
}




PowerOffState::~PowerOffState() {}

void PowerOffState::TurnOn(Heater *device)
{
    device->setMessage("Подготавливаем устройство ");
    device->ChangeState(new PowerOnState());
}

void PowerOffState::TurnOff(Heater *device)
{
}

PowerOnState::~PowerOnState() {}

void PowerOnState::TurnOff(Heater *device)
{
        device->setMessage("Завершаем работу устройства ");
        device->ChangeState(new PowerOffState());

}

void PowerOnState::TurnOn(Heater *device)
{
}
