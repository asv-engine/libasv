
#ifndef ASV_WORLD_H
#define ASV_WORLD_H

#include <list>
#include "time.hpp"

namespace ASV {

class Simulation;

// One tick per second should be perfectly fine
const double WorldTimestep = 1.0;

class World {
  
 public:
  World();
  ~World();

  void reset();
  
  void tick();
  void tick(double step);
  
  double getTime(void);
  long int getTicks(void);
  
 private:
  double time;
  long int ticks;

};

namespace Default {

namespace Worlds {

World *Sol();

}

}

}

#endif
