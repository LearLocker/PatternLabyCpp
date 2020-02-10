#ifndef FACADE_H
#define FACADE_H
#include "ProxyGreenHouse.h"

/**
 * Класс Фасада предоставляет простой интерфейс для сложной логики одной или
 * нескольких подсистем. Фасад делегирует запросы клиентов соответствующим
 * объектам внутри подсистемы. Фасад также отвечает за управление их жизненным
 * циклом. Все это защищает клиента от нежелательной сложности подсистемы.
 */
class Facade {
 protected:
    //Plant *plant;
    //PlantFactory* plantFactory;
    //GreenHouse *greenHouse;
    ProxyGreenHouse *greenHouse;
  /**
   * В зависимости от потребностей вашего приложения вы можете предоставить
   * Фасаду существующие объекты подсистемы или заставить Фасад создать их
   * самостоятельно.
   */
 public:
  /**
   * In this case we will delegate the memory ownership to Facade Class
   */
  Facade( ProxyGreenHouse *greenHouse_ = nullptr)
      //Subsystem2 *subsystem2 = nullptr)
  {
    this->greenHouse = greenHouse_ ?: new ProxyGreenHouse();
    //this->subsystem2_ = subsystem2 ?: new Subsystem2;
  }
  ~Facade() {
    delete greenHouse;
    //delete subsystem2_;
  }
  /**
   * Методы Фасада удобны для быстрого доступа к сложной функциональности
   * подсистем. Однако клиенты получают только часть возможностей подсистемы.
   */
  void Operation() {

      PlantFactory *plantFactory = PlantFactory::getInstance();

      Plant *plant = new Plant(25, 20, 5, "", "Tomato");
      //plantFactory->setPlant(plant);

      greenHouse = new ProxyGreenHouse();
      greenHouse->AddPlant(plant);
      greenHouse->AddLight(new Light());
      greenHouse->AddDevice();
      greenHouse->AddEnviroment();

      greenHouse->Monitor();
  }

  ProxyGreenHouse *getGreenHouse()
  {
      return greenHouse;
  }
};


#endif // FACADE_H
