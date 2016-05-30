
#include <iostream>

#include "component.hpp"

namespace ASV {

// # Input

Input::Input() {
  value = NULL;
  output = NULL;
}

std::string *Input::getName() {
  return &name;
}

// ## Outputs

Input *Output::getInput(std::string name) {
  
  for(std::list<Input*>::iterator iterator = inputs.begin(), end = inputs.end(); iterator != end; ++iterator) {
    if((*iterator)->getName()->compare(name) == 0) return *iterator;
  }

  return NULL;
}

bool Output::hasInput(Input *input) {
  
  for(std::list<Input*>::iterator iterator = inputs.begin(), end = inputs.end(); iterator != end; ++iterator) {
    if(input == *iterator) return true;
  }

  return false;
}

// Returns `false` if the input is already in the list.
bool Output::addInput(Input *input) {
  if(hasInput(input)) return false;
    
  inputs.push_back(input);

  return true;
}

bool Output::removeInput(Input *input) {
  
  for(std::list<Input*>::iterator iterator = inputs.begin(), end = inputs.end(); iterator != end; ++iterator) {
    
    if(input == *iterator) {
      inputs.erase(iterator);

      return true;
    }

  }

  return false;
}

// Returns `false` if `name` does not refer to an existing input.
bool Output::removeInput(std::string name) {

  Input *input = getInput(name);
  
  if(!input) return false;

  return removeInput(input);
}

// # Component

Component::Component() : Ticker() {

}

Component::~Component() {

}

void Component::reset() {
  Ticker::reset();
}

// ## Tick
//
// If called with a double, steps through the component simulation for
// that many seconds; otherwise, runs a single tick.

void Component::tick() {
  Ticker::tick();
}

// ## Components

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
