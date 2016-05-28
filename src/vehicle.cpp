
#include "vehicle.hpp"

namespace ASV {

Vehicle::Vehicle() {
  time = 0;
  ticks = 0;
}

Vehicle::~Vehicle() {

}

// # Tick

bool Vehicle::tick() {
  ticks += 1;
  time += VehicleTimestep;
}

bool Vehicle::tick(double step) {
  for(; step > 0; step -= VehicleTimestep) {
    tick();
  }
}

double Vehicle::getTime(void) {
  return time;
}

long int Vehicle::getTicks(void) {
  return ticks;
}

}

