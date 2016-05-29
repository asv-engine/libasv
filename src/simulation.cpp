
#include <iostream>
#include "simulation.hpp"

namespace ASV {

Simulation::Simulation() {
  reset();
}

Simulation::~Simulation() {

}

void Simulation::reset() {
  time = 0;
  ticks = 0;
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

// Returns `true` if the vehicle already exists.

bool Simulation::hasVehicle(Vehicle *vehicle) {
  
  for(std::list<Vehicle*>::iterator iterator = vehicles.begin(), end = vehicles.end(); iterator != end; ++iterator) {
    if(vehicle == *iterator) return true;
  }

  return false;
}

// Returns `false` if the vehicle is already in the simulation.
bool Simulation::addVehicle(Vehicle *vehicle) {
  if(hasVehicle(vehicle)) return false;
    
  vehicles.push_back(vehicle);

  return true;
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

