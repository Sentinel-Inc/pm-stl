//
// Created by piotr on 16/10/2021.
//

#ifndef COA_CLOCK_TRACER_H_
#define COA_CLOCK_TRACER_H_

#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#define AUTO_TRACER Tracer tracer(__FILE__, __func__)
#define TRACER(x) pm::Tracer tracer(x)
#define SAVE_TRACINGS(x) pm::Tracer::SaveToJSON(x)

namespace pm {
enum class Type {
  BEGIN,
  END
};
struct Tracers {
  Tracers(std::string name, Type type, long long int time_point, size_t thread_id);
  std::string name;
  Type type;
  long long int time_point;
  size_t thread_id;
  std::string Save();
};

class Tracer {
 public:
  Tracer() = delete;
  Tracer(std::string clock_name);
  Tracer(const std::string &file_name, const std::string &function_name);
  Tracer(const Tracer &other) = delete;
  Tracer &operator=(const Tracer &other) = delete;

  ~Tracer();
  static void SaveToJSON(const std::string &filename);

  static std::vector<Tracers> saved_tracers_;

 protected:
  std::string tracer_name_;
  std::chrono::time_point<std::chrono::high_resolution_clock> time_point_;
  size_t thread_id_ = std::hash<std::thread::id>{}(std::this_thread::get_id());
};
}// namespace pm
#endif//COA_CLOCK_TRACER_H_
