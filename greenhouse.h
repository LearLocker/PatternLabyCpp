#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "IGreenHouse.h"
#include "PlantFactory.h"
#include "logger.h"
//#include "cooler.h"
#include "state.h"
#include "sensor.h"

class GreenHouse : public IGreenHouse{
private:
    Logger *log;
    Plant* plants;
    Heater *heater;
    Cooler *cooler;
    Environment *environment;
    Sensor *tempSensor;
    Light *light;

public:
    GreenHouse() {
        InitLog();
    }

    void AddPlant(Plant* plant) {
        plants = PlantFactory::getInstance()->getPlant( plant->getMaxT(), plant->getMinT(), plant->getHumidility(), plant->getInfo(), plant->getName(), log);
        log->log( "Add plant");
    }

    Plant* getPlant()
    {
        return plants;
    }

    void AddSensor(Sensor* sn)
    {
        tempSensor = sn;
        log->log( "Add Temperature Sensor");
    }

    Sensor* getSensor()
    {
        return tempSensor;
    }

    void AddLight(Light *l){
        light = l;
        log->log( "Add Light");
    }

    void AddDevice(){
        heater = new Heater(1, new PowerOffState());
        cooler = new Cooler(2);
    }

    void AddEnviroment(){
        environment = new Environment(heater, cooler, plants, light);
        AddSensor(new Sensor(environment));
    }

    void Monitor()
    {
        environment->SetTimer();
    }

    void InitLog()
    {
        log = new FileLogger("log.txt");
    }
    int GetCurrentTime(){
        return environment->GetCurrentTime();
    }

    int GetDay(){
        return environment->GetDay();
    }

    int GetHour(){
        return environment->GetHour();
    }
    int GetMinute(){
        return environment->GetMinute();
    }

    float GetTemperature(){
        return environment->GetTemperature();
    }

    string GetState(){
        return tempSensor->getMessage();
    }

    string getMessage(){
        return light->getMessage();
    }


};

#endif // GREENHOUSE_H
