//
// Created by piotr on 18/10/2021.
//
#include "pm_include.h"
int main() {
  pm::Logger::Config config{true,
                            true,
                            true,
                            true,
                            true};

  pm::Logger::init(pm::Logger::all, config);
  {
    START_TRACER("first");
    LOG("Hello world");
  }
  TIME_START(name);
  TIME_STOP(name, "name");
  SAVE_TRACINGS("sommy");
  return 0;
}