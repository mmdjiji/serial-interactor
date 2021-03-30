// uart.h
// This file is a part of serial-interactor project.
// For STC8F1K08 device.

// Author: mmdjiji (JiJi)
// GitHub: https://github.com/mmdjiji/serial-interactor

#ifndef _UART_H_
#define _UART_H_

void tiny_delay();

void uart_listen(const long _fosc, const int _baud);

void uart_start();
void uart_stop();

void uart_send_char(char dat);
void uart_send_string(char *dat);

void uart_recv(char dat);

void _uart_interrupt();

#endif // _UART_H_