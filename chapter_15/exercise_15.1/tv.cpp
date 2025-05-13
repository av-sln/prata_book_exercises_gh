// tv.cpp -- реализация методов Tv и Remote
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
  if (volume < MaxVal) {
    ++volume;
    return true;
  } else
      return false;
}

bool Tv:: voldown()
{
  if (volume > MinVal) {
    --volume;
    return true;
  } else
      return false;
}

void Tv::chanup()
{
  if (channel < maxchannel)
    ++channel;
  else
    channel = 1;
}

void Tv::chandown()
{
  if (channel > 1)
    --channel;
  else
    channel = maxchannel;
}

void Tv::settings(Remote& r) const
{
  std::cout << "TV is " << (state == Off? "Off" : "On") << std::endl;
  if (state == On) {
    std::cout << "Volume setting = " << volume << std::endl;
    std::cout << "Channel setting = " << channel << std::endl;
    std::cout << "Mode = " << (mode == Antenna? "antenna" : "cable")
              << std::endl;
    std::cout << "Input = " << (input == TV? "TV" : "DVD") << std::endl;
    std::cout << "Remote mode = "
              << (r.rmode == r.Normal? "Normal" : "interactive") << std::endl;
  }
}

void Tv::setRmode(Remote& rm)
{
  if (state == On) {
    std::cout << "Tv is On.\n";
    rm.rmode = (rm.rmode == rm.Normal? rm.Interactive : rm.Normal);
  } else
      std::cout << "Your TV is turn off.\n";    
}

// Методы Remote
void Remote::showRmode() const
{
  std::cout << "Remote mode = " 
            << (rmode == Normal? "Normal" : "Interactive") << std::endl;
}