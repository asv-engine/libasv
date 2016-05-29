
#include <iomanip>
#include <iostream>
#include <sstream>
#include <math.h>

#include "time.hpp"

namespace ASV {

std::string timeToString(double time) {

  double seconds = fmod(time, SecondsPerMinute);
  int minutes = fmod(time / SecondsPerMinute, MinutesPerHour);
  int hours = fmod(time / SecondsPerHour, HoursPerDay);
  int days = fmod(time / SecondsPerDay, DaysPerYear);
  int years = time / SecondsPerYear;
  
  std::ostringstream ss;

  if(years)
    ss << years << "y ";

  if(years || days)
    ss << days << "d ";
  
  if(years || days || hours)
    ss << hours << "h ";
  
  if(years || days || hours || minutes)
    ss << minutes << "m ";
  
  ss << std::fixed << std::setprecision(2) << seconds << "s";

  return ss.str();
}

// # Ticker

Ticker::Ticker() {
  reset();
}

Ticker::~Ticker() {

}

void Ticker::reset() {
  time = 0;
  ticks = 0;
}

// ## Tick
//
// If called with a double, steps through the ticker simulation for
// that many seconds; otherwise, runs a single tick.

void Ticker::tick() {
  ticks += 1;
  time += 1.0 / ticksPerSecond;
}

void Ticker::step(double step) {

  int theoreticalTickNumber = (time + step) * ticksPerSecond;

  if(ticks > theoreticalTickNumber) return;
  
  // We keep track of in and out times so we don't drift over time.
  float start_time = time;
  
  while(ticks < theoreticalTickNumber - 1) {
    tick();
  }
  
  time = start_time + step;
}

double Ticker::getTime(void) {
  return time;
}

long int Ticker::getTicks(void) {
  return ticks;
}

}
