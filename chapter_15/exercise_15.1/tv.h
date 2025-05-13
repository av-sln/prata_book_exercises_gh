// tv.h -- классы Тv и Remote

#ifndef TV_H_
#define TV_H_

class Remote;

class Tv {
friend class Remote;
public:
  enum {Off, On};
  enum {MinVal, MaxVal = 20};
  enum {Antenna, Cable};
  enum {TV, DVD};

  // Конструктор
  Tv(int s = Off, int mc = 125)
    : state(s), volume(5), maxchannel(mc), mode(Cable), input(TV) {}
  void onoff() { state = (state == On)? Off : On; }
  bool ison() const { return state == On; }
  bool volup();
  bool voldown();
  void chanup();
  void chandown();
  void set_mode() { mode = (mode == Antenna)? Cable : Antenna; }
  void set_input() { input = (input == TV)? DVD : TV; }
  void settings(Remote& r) const;
  void setRmode(Remote& rm);
private:
  int state;      // On или Off
  int volume;     // дискретные уровни громкости
  int maxchannel; // максимальное количество каналов
  int channel;    // текущий канал
  int mode;       // эфирное или кабельное телевидение
  int input;      // TV или DVD
};

class Remote {
friend class Tv;
private:
  int mode;       // управление TV или DVD
  int rmode;      // режим пульта
public:
  enum {Normal, Interactive};
  Remote(int m = Tv::TV, int rm = Normal) : mode(m), rmode(rm) {}
  // Встроенные функции
  bool volup(Tv& t);
  bool voldown(Tv& t);
  void onoff(Tv& t);
  void chanup(Tv& t);
  void chandownd(Tv& t);
  void set_chan(Tv& t, int c);
  void set_mode(Tv& t);
  void set_input(Tv& t);
  // Методы определённые в tv.cpp
  void showRmode() const;
};

// Методы Remote как встроенные функции
inline bool Remote::volup(Tv& t) { return t.volup(); }
inline bool Remote::voldown(Tv& t) { return t.voldown(); }
inline void Remote::onoff(Tv& t) { t.onoff(); }
inline void Remote::chanup(Tv& t) { t.chanup(); }
inline void Remote::chandownd(Tv& t) { t.chandown(); }
inline void Remote::set_chan(Tv& t, int c) { t.channel = c; }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }

#endif