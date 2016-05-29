
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <list>
#include "time.hpp"

namespace ASV {

class Vehicle;

class Component;

class Component : public Ticker {
  
  static const int ticksPerSecond = 100;

 public:
  Component();
  ~Component();

  void reset();
  
  void tick();

  bool hasComponent(Component *component);
  bool addComponent(Component *component);
  bool removeComponent(Component *component);
    
 private:
  std::list<Component*> components;
};

}

#endif
