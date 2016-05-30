
#include "components/resistor.hpp"

namespace ASV {

ResistorComponent::ResistorComponent() : Component() {
  resistance = 1;

  input.setName("input");
  output.setName("output");

  addInput(&input);
}

void ResistorComponent::tick() {
  Component::tick();

  volts input_voltage = 0;
  
  if(input.isConnected())
    input_voltage = input.value->getValueDouble();

  voltage_drop = current * length * resistance;
  
  output.value.setValue(input_voltage - voltage_drop);
}

volts ResistorComponent::getVoltage() {
  return output.value.getValueDouble();
}

}
