
#ifndef ASV_COMPONENT_H
#define ASV_COMPONENT_H

#include <string>
#include <list>

#include "util.hpp"
#include "time.hpp"
#include "units.hpp"
#include "value.hpp"

namespace ASV {

class Vehicle;

class Component;
class Output;

// # Input

class Input : public HasName {

 public:
  Input();
  Input(const char *name);

  bool isConnected();

  Value *value;
  Output *output;

};

// # Output

class Output : public HasName {

 public:
  Output();
  Output(const char *name);

  Input *getInput(std::string name);
  
  bool hasInput(Input *input);
  bool hasInput(std::string name);
  
  bool addInput(Input *input);
  
  bool removeInput(Input *input);
  bool removeInput(std::string name);
  
  Value value;
  std::list<Input*> inputs;
  
};

// # Component

class Component : public Ticker, public HasName {
  
  static const int ticksPerSecond = 10;

 public:
  Component();
  ~Component();

  void reset();
  
  void tick();

  Component *getComponent(std::string name);
  bool addComponent(Component *component);
  bool removeComponent(Component *component);

  
  
  bool hasInput(std::string name);
  bool addInput(Input *input);
  Input *getInput(std::string name);
  
  bool removeInput(Input *input);
  bool removeInput(std::string name);

  
    
  bool hasOutput(std::string name);
  bool addOutput(Output *output);
  Output *getOutput(std::string name);
  
  bool removeOutput(Output *output);
  bool removeOutput(std::string name);

  bool connect(Output *output, Input *input);
    
 protected:
  std::list<Component*> components;
  
  std::list<Input*> inputs;
  std::list<Output*> outputs;
  
};

}

#endif
