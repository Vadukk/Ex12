// Copyright 2021 Vadukk

#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

private:
  TimedDoor& door;
 public:
  explicit DoorTimerAdapter(TimedDoor& newdr) : door(newdr) {}
  void Timeout() override;
};

class TimedDoor : public Door {
  int iTimeout;
  bool opened;
 public:
  explicit TimedDoor(int newTimeout) :
  iTimeout(newTimeout),
  opened(false),
  adapter(new DoorTimerAdapter(*this)) {}
  bool isDoorOpened() override { return opened; }
  void unlock() override;
  void lock() override {opened = false; }
  void DoorTimeOut();
  void throwState();
  int getTime() { return iTimeout; }
};

class Timer {
  TimerClient *client;
  void sleep(int);
 public:
  void tregister(int time, TimerClient* tim);
};

#endif  // INCLUDE_TIMEDDOOR_H_
