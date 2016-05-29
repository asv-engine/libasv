
#include <iomanip>
#include <iostream>
#include <sstream>
#include <math.h>

#include "time.hpp"

namespace ASV {

// # `timeToString`
//
// Converts a time, in seconds, to a string of the form `1y 120d 15h
// 14m 12s`.  Starting from the left, no component is displayed unless
// it's non-zero. (Said another way: the first value will never be 0.)

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

void Ticker::step(seconds increment) {

  // The number of ticks we should be at when `time + step` has
  // elapsed.
  int totalTickNumber = (time + increment) * ticksPerSecond;

  if(ticks >= totalTickNumber) return;
  
  // We keep track of in and out times so we don't drift over time.
  float start_time = time;
  
  while(ticks < totalTickNumber - 1) {
    tick();
  }
  
  time = start_time + increment;
}

// Returns the time, in seconds, since the start of this Ticker.
seconds Ticker::getTime(void) {
  return time;
}

// Returns the number of ticks.
unsigned long int Ticker::getTicks(void) {
  return ticks;
}

}
