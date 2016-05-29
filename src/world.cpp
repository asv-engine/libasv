
#include <iostream>

#include "world.hpp"

namespace ASV {

World::World() {
  reset();
}

World::~World() {

}

void World::reset() {
  time = 0;
  ticks = 0;
}

// # Tick
//
// If called with a double, steps through the world simulation for
// that many seconds; otherwise, runs a single tick.

void World::tick() {
  ticks += 1;
  time += WorldTimestep;
}

void World::tick(double step) {

  int theoreticalTickNumber = (time + step) / WorldTimestep;

  // We don't want to tick if there's not enough time for a tick;
  // otherwise, calling tick(0) would be _guaranteed_ to tick at least
  // once, which is very, very bad.

  if(ticks < theoreticalTickNumber) return;

  // We keep track of in and out times so we don't drift over time.
  float start_time = time;
  
  while(ticks < theoreticalTickNumber - 1) {
    tick();
  }
  
  time = start_time + step;
}

double World::getTime(void) {
  return time;
}

long int World::getTicks(void) {
  return ticks;
}

namespace Default {

namespace Worlds {

World *Sol() {
  World *sol = new World();
  return sol;
}

}

}

}

