#ifndef IGREENHOUSE_H
#define IGREENHOUSE_H
#include <iostream>
#include "plant.h"
#include "sensor.h"
#include "light.h"

class IGreenHouse {
public:
    virtual void AddPlant(Plant* plant) = 0;

    virtual Plant* getPlant() = 0;

    virtual void AddSensor(Sensor* sn) = 0;

    virtual void AddLight(Light *l) = 0;

    virtual void AddDevice() = 0;

    virtual void AddEnviroment() = 0;

    virtual void Monitor() = 0;

    virtual void InitLog() = 0;

    virtual int GetCurrentTime() = 0;

    virtual int GetDay() = 0;

    virtual int GetHour() = 0;

    virtual int GetMinute() = 0;

    virtual float GetTemperature() = 0;

    virtual std::string GetState() = 0;

    //virtual std::string GetCoolerState() = 0;

    virtual std::string getMessage() = 0;
};
#endif // IGREENHOUSE_H
