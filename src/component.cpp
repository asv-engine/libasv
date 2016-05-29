
#include <iostream>

#include "component.hpp"

namespace ASV {

Component::Component() : Ticker() {

}

Component::~Component() {

}

void Component::reset() {
  Ticker::reset();
}

// # Tick
//
// If called with a double, steps through the component simulation for
// that many seconds; otherwise, runs a single tick.

void Component::tick() {
  Ticker::tick();
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
