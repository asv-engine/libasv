
#include <iostream>

#include "vehicle.hpp"

namespace ASV {

Vehicle::Vehicle() {
  reset();
}

Vehicle::~Vehicle() {

}

void Vehicle::reset() {
  time = 0;
  ticks = 0;
}

// # Tick
//
// If called with a double, steps through the vehicle simulation for
// that many seconds; otherwise, runs a single tick.

void Vehicle::tick() {
  ticks += 1;
  time += VehicleTimestep;
}

void Vehicle::tick(double step) {

  // We don't want to tick if there's not enough time for a tick;
  // otherwise, calling tick(0) would be _guaranteed_ to tick at least
  // once, which is very, very bad.

  if(step < VehicleTimestep) return;

  // We keep track of in and out times so we don't drift over time.
  float start_time = time;
  
  for(; step > 0; step -= VehicleTimestep) {
    tick();
  }
  
  time = start_time;
}

double Vehicle::getTime(void) {
  return time;
}

long int Vehicle::getTicks(void) {
  return ticks;
}

}

