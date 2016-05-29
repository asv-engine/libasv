
#ifndef ASV_SIMULATION_H
#define ASV_SIMULATION_H

#include <list>
#include "time.hpp"
#include "world.hpp"
#include "vehicle.hpp"

namespace ASV {

const double SimulationTimestep = RootTimestep;

class Simulation {
  
 public:
  Simulation();
  ~Simulation();

  void reset();
  
  void tick();
  void tick(double step);
  double getTime(void);
  long int getTicks(void);
  
  bool hasVehicle(Vehicle *vehicle);
  bool addVehicle(Vehicle *vehicle);
  bool removeVehicle(Vehicle *vehicle);
    
 private:
  double time;
  long int ticks;

  std::list<Vehicle*> vehicles;
};

}

#endif
