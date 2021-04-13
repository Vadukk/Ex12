// Copyright 2021 Vadukk

#include "TimedDoor.h"
#include <string>
#include <ctime>

void DoorTimerAdapter::Timeout() {
  Timer timer;
  timer.tregister(this->door.getTime(), this);
  this->door.DoorTimeOut();
}

void TimedDoor::unlock() {
  opened = true;
  this->adapter->Timeout();
}

void TimedDoor::DoorTimeOut() {
  throw std::string("close the door!");
}

void TimedDoor::throwState() {
  if (opened) {
    throw std::string("Door is opened! =)");
  } else {
    throw std::string("Door is closed! =(");
  }
}

void Timer::sleep(int t) {
  time_t start = time(nullptr);
  while (time(nullptr) - start < t) {
    continue;
  }
}

void Timer::tregister(int time, TimerClient* tim) {
  sleep(time);
}
