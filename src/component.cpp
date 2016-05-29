
#include <iostream>

#include "component.hpp"

namespace ASV {

Component::Component() {
  reset();
}

Component::~Component() {

}

void Component::reset() {
  time = 0;
  ticks = 0;
}

// # Tick
//
// If called with a double, steps through the component simulation for
// that many seconds; otherwise, runs a single tick.

void Component::tick() {
  ticks += 1;
  time += ComponentTimestep;
}

void Component::tick(double step) {

  // We don't want to tick if there's not enough time for a tick;
  // otherwise, calling tick(0) would be _guaranteed_ to tick at least
  // once, which is very, very bad.

  if(step < ComponentTimestep) return;

  // We keep track of in and out times so we don't drift over time.
  float start_time = time;
  
  for(; step > 0; step -= ComponentTimestep) {
    tick();
  }
  
  time = start_time;
}

double Component::getTime(void) {
  return time;
}

long int Component::getTicks(void) {
  return ticks;
}

// # Components

bool Component::hasComponent(Component *component) {
  
  for(std::list<Component*>::iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator) {
    if(component == *iterator) return true;
  }

  return false;
}

// Returns `false` if the component is already in the component.
bool Component::addComponent(Component *component) {
  if(hasComponent(component)) return false;
    
  components.push_back(component);

  return true;
}

// Returns `true` if component existed (and was therefore removed),
// `false` otherwise. If `false` is returned, the component is
// guaranteed to not have changed.

bool Component::removeComponent(Component *component) {
  
  for(std::list<Component*>::iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator) {
    
    if(component == *iterator) {
      components.erase(iterator);

      return true;
    }

  }

  return false;
}

}
