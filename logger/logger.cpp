#include "logger.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace pm {

Logger::Logger() = default;

void Logger::panic(const std::string &text, Info info) {
  if (config.to_file) {
    Logger::log_file_ << "PANIC:\t" << info << text << std::endl;
  } else {
    std::cerr << "PANIC:\t" << info << text << std::endl;
  }
  exit(1);
}

void Logger::err(const std::string &text, Info info) {
  if (level <= Logger::all) {
    if (config.to_file) {
      Logger::log_file_ << "Error:\t" << info << text << std::endl;
    } else {
      std::cerr << "Error:\t" << info << text << std::endl;
    }
  }
}

void Logger::warn(const std::string &text, Info info) {
  if (level <= Logger::warning) {
    if (config.to_file) {
      Logger::log_file_ << "Warn:\t" << info << text << std::endl;
    } else {
      std::cerr << "Warn:\t" << info << text << std::endl;
    }
  }
}

void Logger::log(const std::string &text, Info info) {
  if (level <= Logger::all) {
    if (config.to_file) {
      Logger::log_file_ << "Info:\t" << info << text << std::endl;
    } else {
      std::clog << "Info:\t" << info << text << std::endl;
    }
  }
}

const Logger &Logger::get_instance() {
  // if instance does not exists create it
  if (!instance) {
    instance = new Logger;
  }
  return *instance;
}

void Logger::true_or_panic(bool condition, const std::string &text, Info info) {
  if (!condition) {
    Logger::panic(text, info);
  }
}

void Logger::true_or_err(bool condition, const std::string &text, Info info) {
  if (!condition) {
    if (config.to_file) {
      Logger::log_file_ << "Error:\t" << info << text << std::endl;
    } else {
      std::cerr << "Error:\t" << info << text << std::endl;
    }
  }
}

void Logger::time_stop(size_t duration, const std::string &description,
                       Logger::Info info) {
  if (config.timing) {
    if (config.to_file) {
      Logger::log_file_ << "Time:\t" << info << description << duration << std::endl;
    } else {
      std::clog << "Time:\t" << info << description << " " << duration << " us" << std::endl;
    }
  }
}

std::fstream &operator<<(std::fstream &in, Logger::Info info) {
  in << ((Logger::config.show_file) ? "[ " + info.file + " ]" : "");
  in << ((Logger::config.show_func) ? "[ " + info.function + " ]" : "");
  in << ((Logger::config.show_line) ? "[ " + std::to_string(info.line) + " ]"
                                    : "");
  in << " ";
  return in;
}

std::ostream &operator<<(std::ostream &in, Logger::Info info) {
  in << ((Logger::config.show_file) ? "[ " + info.file + " ]" : "");
  in << ((Logger::config.show_func) ? "[ " + info.function + " ]" : "");
  in << ((Logger::config.show_line) ? "[ " + std::to_string(info.line) + " ]"
                                    : "");
  in << " ";
  return in;
}

void Logger::init(Logger::Level level, Logger::Config config,
                  std::string path) {
  log_file_.open(path, std::ios::app);
  Logger::config = config;
  Logger::level = level;
}

Logger::Config Logger::config = {false, false, false};
Logger::Level Logger::level = Logger::none;
Logger *Logger::instance = nullptr;
std::fstream Logger::log_file_;

} // namespace mk

