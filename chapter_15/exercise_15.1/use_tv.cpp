// use_tv.cpp -- использование классов TV и Remote

#include <iostream>
#include "tv.h"

int main()
{
  std::cout << std::endl;
  Tv s42;
  Remote grey;
  // Телевизор выключен
  std::cout << "Initial settings for 42\" TV:\n";
  s42.settings(grey);
  // Включить телевизор и изменить канал
  s42.onoff();
  s42.chanup();
  // Отображение текущих настроек
  std::cout << std::endl;
  std::cout << "Current settings for 42\" TV:\n";
  s42.settings(grey);
  // Изменить режим пульта
  s42.setRmode(grey);
  std::cout << std::endl;
  std::cout << "Changed remote mode for 42\" TV:\n";
  s42.settings(grey);
  // Выключить телевизор и попытаться измерить режим пульта
  s42.onoff();
  std::cout << std::endl;
  s42.setRmode(grey);
  // Включить телевизор и с помощью пульта изменить настройки
  s42.onoff();
  grey.set_chan(s42, 32);
  grey.volup(s42);
  grey.volup(s42);
  std::cout << std::endl;
  s42.settings(grey);


  return 0;
}