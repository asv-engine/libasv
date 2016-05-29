
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <list>
#include "time.hpp"

namespace ASV {

class Vehicle;

const int ComponentTimestep = RootTimestep;

class Component;

class Component {
  
 public:
  Component();
  ~Component();

  void reset();
  
  void tick();
  void tick(double step);
  double getTime(void);
  long int getTicks(void);

  bool hasComponent(Component *component);
  bool addComponent(Component *component);
  bool removeComponent(Component *component);
    
 private:
  double time;
  long int ticks;
  
  std::list<Component*> components;
};

}

#endif
