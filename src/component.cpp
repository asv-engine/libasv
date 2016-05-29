
#include "component.hpp"

namespace ASV {

Component::Component() {
  time = 0;
  ticks = 0;
}

Component::~Component() {

}

// # Tick

void Component::tick() {
  ticks += 1;
  time += ComponentTimestep;
}

void Component::tick(double step) {
  for(; step > 0; step -= ComponentTimestep) {
    tick();
  }
}

double Component::getTime(void) {
  return time;
}

long int Component::getTicks(void) {
  return ticks;
}

}

