#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

// Receiver Class
class Light
{
public:
    void on() {
        message = "The light is on\n";
        CurrentState = true;
    }
    void off() {
        message = "The light is off\n";
        CurrentState = false;
    }
    std::string getMessage()
    {
        return message;
    }
private:
    bool CurrentState = false;
    std::string message;
};


#endif // LIGHT_H
