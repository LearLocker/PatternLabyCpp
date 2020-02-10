#ifndef COOLER_H
#define COOLER_H
#include <iostream>

class Mediator;

/**
 * Базовый Компонент обеспечивает базовую функциональность хранения экземпляра
 * посредника внутри объектов компонентов.
 */

class Cooler
{
protected:
    Mediator *mediator_;
public:
    Cooler(int _id, Mediator *mediator = nullptr) : mediator_(mediator){ setId(_id);_CurrentState = false;}

    void set_mediator(Mediator *mediator) {
      this->mediator_ = mediator;
    }

    bool GetCurrentState(){
        return _CurrentState;
    }

    void setId(int id){ this->id = id; }

    int getId(){ return id;}

    void TurnOn(){
        _CurrentState = true;
        //this->mediator_->Notify(this, "Turn on");
    }



    void TurnOff(){
        _CurrentState = false;
        //this->mediator_->Notify(this, "Turn off");
    }

    void setMessage(std::string msg){
        message = msg;
    }


private:
    bool _CurrentState;
    int id;
    std::string message;
};


class Mediator {
public:
 virtual void Notify(Cooler *sender, std::string event) const = 0;
};


#endif // COOLER_H
