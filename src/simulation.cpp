
#include <cassert>
#include "simulation.hpp"

namespace ASV {

Simulation::Simulation() : Ticker() {

}

Simulation::~Simulation() {

}

void Simulation::reset() {
  Ticker::reset();
  
  world = NULL;
}

void Simulation::tick() {
  Ticker::tick();
  
  assert(world);

  seconds simTimestep = 1.0 / ticksPerSecond;
    
  for(Vehicle *vehicle : vehicles) {
    vehicle->step(simTimestep);
  }

  world->step(simTimestep);
}

// # World

bool Simulation::setWorld(World *world) {

  if(this->world) return false;

  this->world = world;
  
  return true;
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

