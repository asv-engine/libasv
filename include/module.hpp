
#ifndef ASV_MODULE_H
#define ASV_MODULE_H

#include <list>
#include "time.hpp"
#include "module.hpp"

namespace ASV {

class Vehicle;

const int ModuleTimestep = RootTimestep;

class Module;

class Module {
  
 public:
  Module();
  ~Module();

  bool tick();
  bool tick(double step);
  double getTime(void);
  long int getTicks(void);
  
 private:
  double time;
  long int ticks;
  
  std::list<Module*> modules;
  
};

}

#endif
