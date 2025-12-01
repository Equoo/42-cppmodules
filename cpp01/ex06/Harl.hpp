#ifndef HARL_HPP
#define HARL_HPP

#include <string>

typedef enum { HARL_DEBUG, HARL_INFO, HARL_WARNING, HARL_ERROR } t_harl_level;

class Harl {
public:
  static void complain(std::string level, std::string str);
  static void setLevel(std::string level);
  static t_harl_level getLevel(void);

private:
  static int level;
  static void level_print(int level, std::string str);
};

#endif
