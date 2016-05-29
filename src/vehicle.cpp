
#include <iostream>

#include "vehicle.hpp"

namespace ASV {

Vehicle::Vehicle() : Ticker() {

}

void Vehicle::reset() {
  Ticker::reset();
}

void Vehicle::tick() {
  Ticker::tick();
}

Component *Vehicle::getRootComponent() {
  return &root_component;
}

}

