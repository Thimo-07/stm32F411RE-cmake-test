#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "stm32f4xx_hal.h"
#define ENDL "\n"
#define logger Clogger::get_instance()

class Clogger
{
public:
  Clogger(const Clogger &) = delete;
  static Clogger &get_instance()
  {
    return _logger_instance;
  }

  void log_blank(const char message[]);
  void log_state(const char state[]);
  void log_event(const char event[]);
  void log_error(const char error[]);
  void log_warning(const char warning[]);
  void log_message(const char message[]);
  void log_debug(const char debug_message[]);

private:
  Clogger();
  ~Clogger();
  void write_uart(const char message[]);
  UART_HandleTypeDef _huart2;
  static Clogger _logger_instance;
};

#endif //LOGGER_HPP