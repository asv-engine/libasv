
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <string>
#include <list>

#include "units.hpp"
#include "time.hpp"
#include "value.hpp"

namespace ASV {

class Vehicle;

class Component;
class Output;

class Input {

 public:
  Input();

  std::string *getName();

 private:
  std::string name;
  
  Value *value;
  Output *output;

};

class Output {

 public:
  Output();

  Input *getInput(std::string name);
  
  bool hasInput(Input *input);
  bool hasInput(std::string name);
  
  bool addInput(Input *input);
  
  bool removeInput(Input *input);
  bool removeInput(std::string name);
  
 private:
  std::string name;
  
  Value *value;
  std::list<Input*> inputs;
  
};

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
  
  bool hasInput(std::string name);
  bool addInput(Input *input);
  bool getInput(std::string name);
  
  bool removeInput(Value *value);
  bool removeInput(std::string name);
    
 private:
  std::list<Component*> components;
  
  std::list<Input*> inputs;
  std::list<Output*> outputs;
  
};

}

#endif
