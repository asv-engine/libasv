
#include <unistd.h>
#include <time.h>
#include <iostream>

#include "asv.h"

int main(int argc, char **argv) {
  ASV::Simulation sim;

  int tickrate = 100;

  int i;

  ASV::Vehicle dumb;

  sim.addVehicle(&dumb);

  while(true) {

    sim.tick(10.0);

    std::cout << "\rSimulation time: " << ASV::timeToString(sim.getTime()) << "    " << std::flush;

    usleep(50000);
  }
  
  return 0;
}
