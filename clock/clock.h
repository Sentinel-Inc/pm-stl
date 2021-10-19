//
// Created by piotr on 15/10/2021.
//

#ifndef COA_CLOCK_CLOCK_H
#define COA_CLOCK_CLOCK_H
#include <chrono>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>

#define AUTO_CLOCK pm::Clock timer(__FILE__, __func__)
#define START_CLOCK(x) pm::Clock timer(x)

#define LINE_CLOCK(x)      \
  {                        \
    Clock timer(__LINE__); \
    x                      \
  }

#define SAVE_TIMINGS(x) pm::Clock::SaveToFile(x)
#define DISPLAY_TIMINGS pm::Clock::DisplayToConsole()

namespace pm {
class Clock {
 public:
  Clock() = delete;
  Clock(std::string clock_name);
  Clock(int line);
  Clock(const std::string &file_name, const std::string &function_name);
  Clock(const Clock &other) = delete;
  Clock &operator=(const Clock &other) = delete;
  ~Clock();
  void Stop();
  void Start();
  static void SaveToFile(const std::string &filename);
  static void DisplayToConsole();

 protected:
  ///for no timings will simply store value in microseconds
  static std::map<std::string, long long unsigned int> timings_;
  static std::stack<Clock *> clocks_;
  std::string clock_name_;
  std::chrono::time_point<std::chrono::high_resolution_clock> time_point_;
};
}// namespace pm
#endif//COA_CLOCK_CLOCK_H_
