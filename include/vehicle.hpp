
#ifndef ASV_VEHICLE_H
#define ASV_VEHICLE_H

#include <list>
#include "time.hpp"
#include "component.hpp"

namespace ASV {

class Simulation;

const int VehicleTimestep = RootTimestep;

class Vehicle {
  
 public:
  Vehicle();
  ~Vehicle();

  bool tick();
  bool tick(double step);
  double getTime(void);
  long int getTicks(void);
  
 private:
  double time;
  long int ticks;
  
  std::list<Component*> components;
};

}

#endif
