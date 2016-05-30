
#ifndef ASV_VEHICLE_H
#define ASV_VEHICLE_H

#include <list>
#include "time.hpp"
#include "component.hpp"

namespace ASV {

class Simulation;

class Vehicle : public Ticker {
  
  static const int ticksPerSecond = 100;

 public:
  Vehicle();

  void reset();
  
  void tick();

  Component *getRootComponent();

 private:
  Component root_component;
};

}

#endif
