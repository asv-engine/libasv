
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

const double RootTimestep = 1.0 / 100;

std::string timeToString(double time);

}

#endif
