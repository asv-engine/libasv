
#include "component.hpp"
#include "components/battery.hpp"

namespace ASV {

// # Input

BatteryComponent::BatteryComponent() : Component() {
  voltage = 42.50;
  
  input.setName("charger");
  output.setName("output");

  addInput(&input);
  addOutput(&output);
}

volts BatteryComponent::getVoltage() {
  return voltage;
}

void BatteryComponent::tick() {
  Component::tick();
  
  output.value.setValue(voltage);
}

}
