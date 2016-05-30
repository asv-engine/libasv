
#include <unistd.h>
#include <time.h>
#include <iostream>

#include "asv.h"

void buildPad(ASV::Vehicle *pad) {
  ASV::Component *root = pad->getRootComponent();
  
  ASV::BatteryComponent *battery = new ASV::BatteryComponent();
  ASV::ResistorComponent *resistor = new ASV::ResistorComponent();

  battery->setName("battery");
  resistor->setName("resistor");

  root->connect(battery->getOutput("output"), resistor->getInput("input"));
  
  root->addComponent(battery);
  root->addComponent(resistor);
}

int main(int argc, char **argv) {
  ASV::Simulation sim;

  ASV::Vehicle pad;

  sim.setWorld(ASV::Default::Worlds::Sol());
  sim.addVehicle(&pad);

  buildPad(&pad);

  ASV::BatteryComponent *battery = (ASV::BatteryComponent*) pad.getRootComponent()->getComponent("battery");
  ASV::ResistorComponent *resistor = (ASV::ResistorComponent*) pad.getRootComponent()->getComponent("resistor");

  while(true) {

    // Tick 1 minute at a time
    sim.step(60);

    /// std::cout << "\rSimulation time: " << ASV::timeToString(sim.getTime()) << "    " << std::flush;
    std::cout << "\rBattery voltage: " << resistor->getVoltage() << "    " << std::flush;
  }
  
  return 0;
}
