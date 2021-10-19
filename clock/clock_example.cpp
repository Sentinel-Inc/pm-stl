//
// Created by piotr on 15/10/2021.
//
#include "clock.h"
#include "tracer.h"
#include <iostream>
#include <thread>

int Fun2();

int Fun() {

  AUTO_CLOCK;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  // note that Fun() invokes Fun2(), and by doing that stops its own clock
  Fun2();

  return 0;
}

int Fun2() {
  AUTO_CLOCK;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return 0;
}

int HalfOfFun() {

  AUTO_CLOCK;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  return 0;
}

int main() {
  std::cout << "Example 1 non additive*, time measurement across 3 functions\nresults appear in console with simplistic interpretation\n";
  Fun();
  HalfOfFun();
  SAVE_TIMINGS("example1.txt");

  return 0;
}