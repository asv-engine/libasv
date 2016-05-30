
#include "value.hpp"

namespace ASV {

Value::Value() {
  setValue(0);
}

Value::Value(std::string name) : Value() {
  setName(name);
}

Value::~Value() {

}

void Value::setName(std::string name) {
  this->name = name;
}

void Value::setName(const char *name) {
  this->name.assign(name);
}

std::string *Value::getName() {
  return &name;
}

// # Type

void Value::setType(Type type) {
  value_type = type;
}

Value::Type Value::getType() {
  return value_type;
}

bool Value::isType(Type type) {
  return value_type == type;
}

// # Value
void Value::setValue(int i) {
  setType(INT);
  value.i = i;
}

void Value::setValue(double d) {
  setType(DOUBLE);
  value.d = d;
}

// ## Get value

int Value::getValueInt(int def) {
  if(isType(INT)) return value.i;
  return def;
}

int Value::getValueInt() {
  return getValueInt(0);
}

double Value::getValueDouble(double def) {
  if(isType(DOUBLE)) return value.d;
  return def;
}

double Value::getValueDouble() {
  return getValueDouble(0.0);
}

}
