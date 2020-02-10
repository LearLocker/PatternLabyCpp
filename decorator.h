#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>

class INotifier {
public:
    virtual std::string notify(std::string message) = 0;
    virtual ~INotifier(){}
    //std::string message;
};

class Notifier : public INotifier{
public:
    virtual std::string notify(std::string message){
        return "Turn on " + message;
    }
};

class Decorator : public INotifier {
  /**
   * @var Component
   */
 protected:
  INotifier* wrappee;

 public:
  Decorator(INotifier* component) : wrappee(component) {
  }
  /**
   * Декоратор делегирует всю работу обёрнутому компоненту.
   */
  virtual std::string notify(std::string message){
      return wrappee->notify(message);
  }
};


class DecoratorOne : public Decorator {
public:
    DecoratorOne(INotifier* component) : Decorator(component) {}

    std::string notify(std::string message) {
        std::cout << '\a';
        return Decorator::notify(message);
    }
};

#endif // DECORATOR_H
