
#ifndef ASV_SIMULATION_H
#define ASV_SIMULATION_H

#include <list>
#include "time.hpp"
#include "world.hpp"
#include "vehicle.hpp"

namespace ASV {

class Simulation : public Ticker {
  
  static const int ticksPerSecond = 100;
  
 public:
  Simulation();
  ~Simulation();

  void reset();
  
  void tick();

  bool setWorld(World *world);
  
  bool hasVehicle(Vehicle *vehicle);
  bool addVehicle(Vehicle *vehicle);
  bool removeVehicle(Vehicle *vehicle);
    
 private:
  World *world;
  std::list<Vehicle*> vehicles;
};

}

#endif
