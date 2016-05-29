
#include <iostream>

#include "world.hpp"

namespace ASV {

World::World() : Ticker() {

}

World::~World() {

}

void World::reset() {
  Ticker::reset();
}

void World::tick() {
  Ticker::tick();
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

