#ifndef SENSOR_H
#define SENSOR_H


#include <iostream>
#include "decorator.h"
#include <vector>
#include <string.h>
#include "command.h"
#include "state.h"
#include "cooler.h"
#include "Plant.h"
#include <QTimer>
#include <QTime>

using namespace std;

class Observer;
class Sensor;
class Mediator;
class ConcreteMediator;

class Observer
{
public:
    Observer() {}
    ~Observer() {}
    virtual void Update() = 0;
};

class Subject
{
public:
    Subject() {}

    virtual ~Subject() {}

    virtual void Attach(Observer *o) = 0;

    virtual void Detach(Observer*o) = 0;

    virtual void Notify() = 0;

};


class Environment : public Subject//, public QObject
{
    //Q_OBJECT
public:
    Environment(Heater *h, Cooler *c, Plant *p, Light *l)
    {
        Day = 0; Hour = 8; Minute= 0; Sec= 0;
        _heater = h;
        _cooler = c;
        _plant= p;
        _light = l;
        Temperature = 15;
    }

    void Attach(Observer *o)
    {
        _observers.push_back(o);
    }

    void Detach(Observer*o)
    {
        int count = _observers.size();
        int i;

        for (i = 0; i < count; i++) {
            if(_observers[i] == o)
                break;
        }
        if(i < count)
            _observers.erase(_observers.begin() + i);
    }


    void Notify()
    {
        int count = _observers.size();

        for (int i = 0; i < count; i++)
            (_observers[i])->Update();
    }

    float GetTemperature()
    {
        return Temperature;
    }

    void Entropy()
    {
            Temperature = Temperature+3-(int)(rand()/(RAND_MAX/6));
         //condition->acidity=condition->acidity+2-(int)(rand()/(RAND_MAX/4));

        Notify();
    }

    void Stable()
    {
        if ( _heater->GetCurrentState() == true && _cooler->GetCurrentState() == false)
        {
            Temperature+=(0.1);
        }

        else            
            if (_cooler->GetCurrentState()==true && _heater->GetCurrentState() == false)
        {
            Temperature-=(0.1);
        }

        if((Hour >= 0 && Hour <= 8) || (Hour >= 18 && Hour <= 24))
        {
            setCommand(new LightOnCommand(_light));
            SetLight();
        }
        else
        {
            setCommand(new LightOffCommand(_light));
            SetLight();
        }
        Notify();
    }

    void SetTimer()
    {
        PlantDayHour = new QTime(0,0,0,0);
        PlantDayHour->start();

        _timer1 = new QTimer();
        _timer1->setInterval(25000);
        _timer1->start();
        QObject::connect(_timer1, &QTimer::timeout, [this]{Entropy();});

        _timer2 = new QTimer();
        _timer2->setInterval(1000);
        _timer2->start();
        QObject::connect(_timer2, &QTimer::timeout, [this]{Stable();});

        QTimer* _timer3 = new QTimer();
        _timer3->setInterval(250);
        _timer3->start();
        QObject::connect(_timer3, &QTimer::timeout, [this]{GetCurTime();});
    }

    void setCommand(Command *cmd)
    {
        mCmd = cmd;
    }

    void SetLight()
    {
        mCmd->execute();
    }

    void GetCurTime()
    {
        Minute++;
        /*if(Sec > 59)
        {
            Sec = 0;
            Minute++;
        }*/

        if(Minute > 59)
        {
            Minute =0;
            Hour++;
        }
        if(Hour == 24)
        {
            Hour = 0;
            Day++;
        }
    }

    int GetCurrentTime()
    {
       return PlantDayHour->elapsed();
    }

    int GetDay()
    {
       return Day;
    }

    int GetHour()
    {
       return Hour;
    }

    int GetMinute()
    {
       return Minute;
    }

    int GetSec()
    {
       return Sec;
    }

    Plant* GetPlant()
    {
        return _plant;
    }

    Heater* GetHeater()
    {
        return _heater;
    }

    Cooler* GetCooler()
    {
        return _cooler;
    }

private:
    vector<Observer*> _observers;
    Command *mCmd;
    float Temperature;
    QTimer* _timer1;
    QTimer* _timer2;
    QTime *PlantDayHour;
    int Day;
    int Hour;
    int Minute;
    int Sec;
    Heater* _heater;

    Cooler* _cooler;

    Plant * _plant;
    Light *_light;
};








/**
* Конкретные Посредники реализуют совместное поведение, координируя отдельные
* компоненты.
*/
class Sensor: public Observer
{
public:
    Sensor(Environment *s)
    {
        _subject = s;
        _subject->Attach(this);
        setNotifier();
    }

    void SetEnvironment(Environment *s)
    {
        _subject = s;
        _subject->Attach(this);
    }

    ~Sensor()
    {
        _subject->Detach(this);
    }

    void Update()
    {
       if (_subject->GetTemperature() > _subject->GetPlant()->getMaxT())
        {
            _subject->GetCooler()->TurnOn();
            _subject->GetHeater()->TurnOff();
            message = notifier->notify("Cooler");
        }
        else if (_subject->GetTemperature() < _subject->GetPlant()->getMinT())
        {
            _subject->GetHeater()->TurnOn();            
            _subject->GetCooler()->TurnOff();
            message = notifier->notify("Heater");
        }
    }


    void setNotifier(){
        notifier = new Notifier();
        notifier = new DecoratorOne(notifier);
    }

    INotifier* getNotifier(){
        return notifier;
    }

    std::string getMessage(){
        return message;
    }

private:
    std::string message;
    INotifier *notifier;
    Environment *_subject;
};


#endif // SENSOR_H
