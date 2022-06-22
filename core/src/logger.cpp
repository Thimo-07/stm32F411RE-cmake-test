#include "logger.hpp"
#include <stdio.h>
#include <string.h>

Clogger Clogger::_logger_instance;
Clogger &logger_instance = Clogger::get_instance();

void Clogger::log_state(const char state[])
{
  write_uart("[STATE]: ");
  write_uart(state);
  write_uart(ENDL);
}

void Clogger::log_event(const char event[])
{
  write_uart("[EVENT]: ");
  write_uart(event);
  write_uart(ENDL);
}

void Clogger::log_error(const char error[])
{
  write_uart("[ERROR]: ");
  write_uart(error);
  write_uart(ENDL);
}

void Clogger::log_warning(const char warning[])
{
  write_uart("[WARNING]: ");
  write_uart(warning);
  write_uart(ENDL);
}

void Clogger::log_message(const char message[])
{
  write_uart("[MESSAGE]: ");
  write_uart(message);
  write_uart(ENDL);
}

void Clogger::log_debug(const char debug_message[])
{
  write_uart("[DEBUG]: ");
  write_uart(debug_message);
  write_uart(ENDL);
}

void Clogger::log_blank(const char message[])
{
  write_uart(message);
}

void Clogger::write_uart(const char message[])
{
  HAL_UART_Transmit(&_huart2, (uint8_t *)message, strlen(message), strlen(message) * 2);
}

Clogger::Clogger()
{
  _huart2.Instance = USART2;
  _huart2.Init.BaudRate = 115200;
  _huart2.Init.WordLength = UART_WORDLENGTH_8B;
  _huart2.Init.StopBits = UART_STOPBITS_1;
  _huart2.Init.Parity = UART_PARITY_NONE;
  _huart2.Init.Mode = UART_MODE_TX_RX;
  _huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  _huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&_huart2) != HAL_OK)
  {
    while(1){}
  }
}

Clogger::~Clogger()
{
}