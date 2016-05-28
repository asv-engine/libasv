
#include <iomanip>
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

}
