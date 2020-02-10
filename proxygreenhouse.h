#ifndef PROXYGREENHOUSE_H
#define PROXYGREENHOUSE_H
#include "igreenhouse.h"
#include "greenhouse.h"

class ProxyGreenHouse : public IGreenHouse
{
private:
    IGreenHouse *greenhouse;
public :
    ProxyGreenHouse() {
        greenhouse = new GreenHouse();
    }

    virtual void AddPlant(Plant* plant) {
        greenhouse->AddPlant(plant);
    }

    void AddDevice(){
        greenhouse->AddDevice();
    }

    void AddEnviroment(){
        greenhouse->AddEnviroment();
    }

    virtual Plant* getPlant()
    {
        return greenhouse->getPlant();
    }

    virtual void AddSensor(Sensor* sn)
    {
        greenhouse->AddSensor(sn);
    }

    virtual void AddLight(Light *l){
        greenhouse->AddLight(l);
    }

    virtual void Monitor()
    {
        greenhouse->Monitor();
    }

    virtual void InitLog()
    {
        greenhouse->InitLog();
    }

    virtual int GetCurrentTime(){
        return greenhouse->GetCurrentTime();
    }

    virtual int GetDay(){
        return greenhouse->GetDay();
    }

    virtual int GetHour(){
        return greenhouse->GetHour();
    }

    virtual int GetMinute(){
        return greenhouse->GetMinute();
    }

    virtual float GetTemperature(){
        return greenhouse->GetTemperature();
    }

    virtual string GetState(){
        return greenhouse->GetState();
    }

    /*virtual string GetCoolerState(){
        return greenhouse->GetCoolerState();
    }*/

    virtual string getMessage(){
        return greenhouse->getMessage();
    }
};
#endif // PROXYGREENHOUSE_H
