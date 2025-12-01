
#include "Harl.hpp"
#include <iostream>
#include <string>
#include <sys/types.h>

const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const std::string levels_colors[] = {"\033[34m", "\033[32m", "\033[93m",
                                     "\033[31m"};

int Harl::level = HARL_INFO;

void Harl::setLevel(std::string defaultLevel) {
  level = HARL_INFO;

  for (int i = 0; i < 4; i++) {
    if (levels[i] == defaultLevel) {
      level = (t_harl_level)i;
      break;
    }
  }
}

void Harl::complain(std::string level, std::string str) {
  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {

      switch (Harl::level) {
          case HARL_DEBUG:
            level_print(i, str);
          case HARL_INFO:
            level_print(i, str);
          case HARL_WARNING:
            level_print(i, str);
          case HARL_ERROR:
            level_print(i, str);
          default:
            return;    
      }
      break;
    }
  }
}

static void displayTimestamp() {
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[32];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, sizeof(buffer) - 1, "%Y-%m-%dT%H:%M:%S", timeinfo);
  std::cout << "\033[90m" << buffer << "\033[0m";
}

void Harl::level_print(int level, std::string str) {
  displayTimestamp();
  std::cout << " " << levels_colors[level] << "[" << levels[level] << "] "
            << "\033[0m" << str << std::endl;
}
