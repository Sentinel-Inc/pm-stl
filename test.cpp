//
// Created by piotr on 18/10/2021.
//
#include "pm_include.h"
int main(){
  mk::Logger::Config config{true,
                            true,
                            true,
                            false,
                            true };

  mk::Logger::init(mk::Logger::all, config);
  {
    START_TRACER("first");
    LOG("Hello world");
  }
  SAVE_TRACINGS("sommy");
  return 0;
}