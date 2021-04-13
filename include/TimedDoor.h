// Copyright 2021 Vadukk

#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

class DoorTimerAdapter;
class Timer;
class Door;
class TimedDoor;
class TimerClient {
 public:
  virtual void Timeout() = 0;
};
class Door {
 public:
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual bool isDoorOpened() = 0;
};
class DoorTimerAdapter : public TimerClient {
 private:
  TimedDoor& door;
 public:
  explicit DoorTimerAdapter(TimedDoor& newdr) : door(newdr) {}
  void Timeout() override;
};

class TimedDoor : public Door {
 private:
  DoorTimerAdapter * adapter;
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
