
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <list>
#include "time.hpp"
#include "module.hpp"

namespace ASV {

class Vehicle;

const int ComponentTimestep = RootTimestep;

class Component;

class Component {
  
 public:
  Component();
  ~Component();

  bool tick();
  bool tick(double step);
  double getTime(void);
  long int getTicks(void);
  
 private:
  double time;
  long int ticks;
  
  std::list<Component*> components;
  
  std::list<Module*> modules;
  
};

}

#endif