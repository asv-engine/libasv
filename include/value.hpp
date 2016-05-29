
#ifndef ASV_VALUE_H
#define ASV_VALUE_H

#include <string>
#include <list>

namespace ASV {

class Value {
  
 public:
  
  enum Type {
    INT,
    DOUBLE
  };

  Value();
  Value(std::string name);
  ~Value();

  void setName(std::string name);
  void setName(const char *name);
  std::string getName();
  
  Type getType();
  bool isType(Type type);
  
  void setValue(int i);
  void setValue(double d);
  
  int getValueInt(int def);
  int getValueInt();
  double getValueDouble(double def);
  double getValueDouble();

 private:
  void setType(Type type);
  std::string name;
  
  union {
    int i;
    double d;
  } value;

  Type value_type;
  
};

}

#endif
