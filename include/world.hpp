
#ifndef ASV_WORLD_H
#define ASV_WORLD_H

#include <list>
#include "time.hpp"

namespace ASV {

class Simulation;

class World : public Ticker {
  
  static const int ticksPerSecond = 100;

 public:
  World();
  ~World();

  void reset();
  
  void tick();
  
 private:

};

namespace Default {

namespace Worlds {

World *Sol();

}

}

}

#endif
