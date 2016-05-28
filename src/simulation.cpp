
#include "simulation.hpp"

namespace ASV {

Simulation::Simulation() {
  time = 0;
  ticks = 0;
}

Simulation::~Simulation() {

}

// # Tick

bool Simulation::tick() {
  ticks += 1;
  time += SimulationTimestep;
}

bool Simulation::tick(double step) {
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

bool Simulation::addVehicle(Vehicle *vehicle) {
  vehicles.push_back(vehicle);
}

}

