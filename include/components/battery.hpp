
#ifndef ASV_COMPONENT_BATTERY_H
#define ASV_COMPONENT_BATTERY_H

#include <list>

#include "component.hpp"
#include "units.hpp"
#include "value.hpp"

namespace ASV {

class BatteryComponent : public Component {

 public:
  BatteryComponent();

  void tick();

  volts getVoltage();

 private:

  Input input;
  Output output;
  
  volts voltage;
  amp_hours capacity;
};

}

#endif
