#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
#include <map>
#include <iostream>
#include "logger.h"


class Factory {
public:    
    virtual ~Factory() {}
};
class PlantFactory : Factory
{
    std::map<std::string, Plant*> plants;
    PlantFactory(){}
    ~PlantFactory() {}

    PlantFactory(PlantFactory const&); // реализация не нужна
    PlantFactory& operator= (PlantFactory const&);  // и тут

public:
    Plant* getPlant(double max, double min, double humidility, std::string info, std::string name, Logger *log)
    {
        Plant* plant = plants[name];
        if (plant == NULL) {
            log->log( "Plant \"" + name + "\" is not in the factory. Adding this to the factory");
            plant = new Plant(max, min, humidility, info, name);
            plants[name] = plant;            
        }
        else log->log("Plant \""+ name + "\" is already in the factory");
        return plant;
    }

    static PlantFactory* getInstance() {
        static PlantFactory plantFactory;
        return &plantFactory;
    }
};




#endif // PLANTFACTORY_H
