
#ifndef ASV_UNITS_H
#define ASV_UNITS_H

#include <string>

namespace ASV {

typedef double meters;

typedef double square_meters;
typedef double cubic_meters;

typedef double kilograms;

typedef double newtons;

typedef double newton_meters;

typedef double volts;
typedef double amps;
typedef double amp_hours;
typedef double ohms;
typedef double watts;

typedef double kilopascal;

enum Unit {
  METERS,
  
  SQUARE_METERS,
  CUBIC_METERS,
  
  KILOGRAM,
  
  NEWTON,
  NEWTON_METER,
  
  VOLTS,
  AMPS,
  AMP_HOURS,
  OHMS,
  WATTS,
  
  KILOPASCALS
};

}

#endif

