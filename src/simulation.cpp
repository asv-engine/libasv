
#include <iostream>
#include "simulation.hpp"

namespace ASV {

Simulation::Simulation() {
  time = 0;
  ticks = 0;
}

Simulation::~Simulation() {

}

// # Tick

void Simulation::tick() {
  ticks += 1;
  time += SimulationTimestep;

  for(Vehicle *vehicle : vehicles) {
    vehicle->tick(SimulationTimestep);
  }
  
}

void Simulation::tick(double step) {
  for(; step > 0; step -= SimulationTimestep) {
    tick();
  }
}

double Simulation::getTime(void) {
  return time;
}

long int Simulation::getTicks(void) {
  return ticks;
}

// # Vehicles

Vehicle *Simulation::addVehicle(Vehicle *vehicle) {
  vehicles.push_back(vehicle);

  return vehicle;
}

// Returns `true` if vehicle existed (and was therefore removed),
// `false` otherwise. If `false` is returned, the simulation is
// guaranteed to not have changed.

bool Simulation::removeVehicle(Vehicle *vehicle) {
  
  for(std::list<Vehicle*>::iterator iterator = vehicles.begin(), end = vehicles.end(); iterator != end; ++iterator) {
    
    if(vehicle == *iterator) {
      vehicles.erase(iterator);

      return true;
    }

  }

  return false;
}

}

