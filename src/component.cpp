
#include <iostream>

#include "component.hpp"

namespace ASV {

// # Input

Input::Input() {
  value = NULL;
  output = NULL;
}

Input::Input(const char *name) : Input() {
  setName(name);
}

bool Input::isConnected() {
  if(value) return true;
  
  return false;
}

// # Output

Output::Output() {

}

Output::Output(const char *name) : Output() {
  setName(name);
}

// ## Inputs

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

Component *Component::getComponent(std::string name) {
  
  for(std::list<Component*>::iterator iterator = components.begin(), end = components.end(); iterator != end; ++iterator) {
    if((*iterator)->getName()->compare(name) == 0) return *iterator;
  }

  return NULL;
}

bool Component::addComponent(Component *component) {
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

// ## Inputs

Input *Component::getInput(std::string name) {
  
  for(std::list<Input*>::iterator iterator = inputs.begin(), end = inputs.end(); iterator != end; ++iterator) {
    if((*iterator)->getName()->compare(name) == 0) return *iterator;
  }

  return NULL;
}

// Returns `false` if the input is already in the list.
bool Component::addInput(Input *input) {
  inputs.push_back(input);

  return true;
}

bool Component::removeInput(Input *input) {
  
  for(std::list<Input*>::iterator iterator = inputs.begin(), end = inputs.end(); iterator != end; ++iterator) {
    
    if(input == *iterator) {
      inputs.erase(iterator);

      return true;
    }

  }

  return false;
}

// Returns `false` if `name` does not refer to an existing input.
bool Component::removeInput(std::string name) {
  return removeInput(getInput(name));
}

// ## Outputs

Output *Component::getOutput(std::string name) {
  
  for(std::list<Output*>::iterator iterator = outputs.begin(), end = outputs.end(); iterator != end; ++iterator) {
    if((*iterator)->getName()->compare(name) == 0) return *iterator;
  }

  return NULL;
}

// Returns `false` if the output is already in the list.
bool Component::addOutput(Output *output) {
  outputs.push_back(output);

  return true;
}

bool Component::removeOutput(Output *output) {
  
  for(std::list<Output*>::iterator iterator = outputs.begin(), end = outputs.end(); iterator != end; ++iterator) {
    
    if(output == *iterator) {
      outputs.erase(iterator);

      return true;
    }

  }

  return false;
}

// Returns `false` if `name` does not refer to an existing output.
bool Component::removeOutput(std::string name) {
  return removeOutput(getOutput(name));
}

bool Component::connect(Output *output, Input *input) {
  input->value = &(output->value);
  output->addInput(input);
}

}
