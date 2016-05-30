
#include <unistd.h>
#include <time.h>
#include <iostream>

#include "asv.h"

int main(int argc, char **argv) {
  ASV::Simulation sim;

  ASV::Vehicle dumb;

  sim.setWorld(ASV::Default::Worlds::Sol());
  sim.addVehicle(&dumb);

  while(true) {

    // Tick 10 seconds at a time.
    sim.step(60 * 60 * 24);

    std::cout << "\rSimulation time: " << ASV::timeToString(sim.getTime()) << "    " << std::flush;
  }
  
  return 0;
}
