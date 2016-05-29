
#ifndef ASV_VEHICLE_H
#define ASV_VEHICLE_H

#include <list>
#include "time.hpp"
#include "component.hpp"

namespace ASV {

class Simulation;

// The `Vehicle` is at _worst_ `VehicleTimestep` behind the
// `Simulation`. It will never be in front.
const double VehicleTimestep = RootTimestep;

class Vehicle {
  
 public:
  Vehicle();
  ~Vehicle();

  void reset();
  
  void tick();
  void tick(double step);
  void tickTo(double step);
  double getTime(void);
  long int getTicks(void);
  
 private:
  double time;
  long int ticks;
  
  std::list<Component*> components;
};

}

#endif
