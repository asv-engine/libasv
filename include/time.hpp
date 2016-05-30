
#ifndef ASV_TIME_H
#define ASV_TIME_H

#include <string>

namespace ASV {

const int SecondsPerMinute = 60;
const int MinutesPerHour   = 60;
const int SecondsPerHour   = SecondsPerMinute * MinutesPerHour;

const int HoursPerDay      = 24;
const int SecondsPerDay    = SecondsPerHour * HoursPerDay;

const int DaysPerYear      = 365;
const int SecondsPerYear   = SecondsPerDay * DaysPerYear;

std::string timeToString(double time);

typedef double seconds;

class Ticker {

  static const int ticksPerSecond = 100;
  
 public:
  Ticker();
  ~Ticker();

  void reset();
  
  void tick();
  void step(seconds step);
  
  seconds getTime(void);
  unsigned long int getTicks(void);
  
 private:
  double time;
  unsigned long int ticks;
};

}

#endif
