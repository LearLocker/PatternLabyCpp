#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>

class Plant
{
    double MaxTemperature = 0;
    double MinTemperature = 0;
    double Humidility = 0;
    std::string info;
    std::string name;

public:
    double getMaxT() {
        return MaxTemperature;
    }

    double getMinT() {
        return MinTemperature;
    }

    double getHumidility() {
        return Humidility;
    }

    std::string getInfo() {
        return info;
    }

    std::string getName() {
        return name;
    }

    void Display() {
        std::cout << "Plant name: " << name << ", info: " << info << ", humidility: " << Humidility << ", maxT: " << MaxTemperature << ", minT: " << MinTemperature << std::endl;
    }

    Plant(double max, double min, double humidility, std::string info, std::string name) {
        MaxTemperature = max;
        MinTemperature = min;
        Humidility = humidility;
        this->info = info;
        this->name = name;
    }

    ~Plant() {}
};

#endif // PLANT_H
