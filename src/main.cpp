// Copyright 2021 Vadukk

#include "TimedDoor.h"
#include <iostream>

int main() {
  TimedDoor tDoor(5);
  try {
    tDoor.lock();
    tDoor.throwState();
  }
  catch(std::string message) {
    std::cout << message;
  }

  return 0;
}
