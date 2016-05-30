
#include <iostream>

#include "util.hpp"

namespace ASV {

// # HasName

void HasName::setName(std::string *name) {
  this->name = *name;
}

void HasName::setName(const char *name) {
  this->name = name;
}

std::string *HasName::getName() {
  return &name;
}

}
