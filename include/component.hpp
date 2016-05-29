
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <string>
#include <list>

#include "time.hpp"
#include "value.hpp"

namespace ASV {

class Vehicle;

class Component;

class Component : public Ticker {
  
  static const int ticksPerSecond = 100;

 public:
  Component();
  ~Component();

  void reset();
  
  void tick();

  bool hasComponent(Component *component);
  bool addComponent(Component *component);
  bool removeComponent(Component *component);
  
  bool hasInput(Value *value);
  bool addInput(Value *value);
  bool getInput(std::string name);
  bool removeInput(Value *value);
  bool removeInput(std::string name);
    
 private:
  std::list<Component*> components;
  
  std::list<Value*> inputs;
  std::list<Value*> outputs;
  
};

}

#endif
