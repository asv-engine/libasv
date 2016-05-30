
#ifndef ASV_COMPONENT_RESISTOR_H
#define ASV_COMPONENT_RESISTOR_H

#include <list>

#include "component.hpp"
#include "units.hpp"
#include "value.hpp"

namespace ASV {

class ResistorComponent : public Component {

 public:
  ResistorComponent();

  void tick();

  volts getVoltage();

 private:

  Input input;
  Output output;
  
  meters length;
  volts voltage_drop;
  amps current;
  ohms resistance;
};

}

#endif
