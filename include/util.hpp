
#ifndef ASV_UTIL_H
#define ASV_UTIL_H

#include <string>

namespace ASV {

class HasName {

 public:
  
  void setName(std::string *name);
  void setName(const char *name);
  std::string *getName();

 private:
  std::string name;
  
};

}

#endif
