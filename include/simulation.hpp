
#ifndef ASV_SIMULATION_H
#define ASV_SIMULATION_H

#include <list>
#include "time.hpp"
#include "vehicle.hpp"

namespace ASV {

const double SimulationTimestep = RootTimestep;

class Simulation {
  
 public:
  Simulation();
  ~Simulation();

  bool tick();
  bool tick(double step);
  double getTime(void);
  long int getTicks(void);
  
  bool addVehicle(Vehicle *vehicle);
    
 private:
  double time;
  long int ticks;

  std::list<Vehicle*> vehicles;
};

}

#endif
