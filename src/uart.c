// uart.c
// This file is a part of serial-interactor project.
// For STC8F1K08 device.

// Author: mmdjiji (JiJi)
// GitHub: https://github.com/mmdjiji/serial-interactor

#include "uart.h"
#include <stc8.h>

void tiny_delay() {
	unsigned int t = 5;
	while(--t);
}

void uart_listen(const long _fosc, const int _baud) {
	SCON = 0x50;
	AUXR |= 0x40;
	AUXR &= 0xFE;
	TMOD &= 0x0F;
	TL1 = (65536-(_fosc/4/_baud));
	TH1 = ((65536-(_fosc/4/_baud))>>8);
	ET1 = 0;
	TR1 = 1;
	uart_start();
}

void uart_start() {
	EA = 1;
	ES = 1;
}

void uart_stop() {
	ES = 0;
}

void uart_send_char(char dat) {
	SBUF = dat;
	while(!TI);
	TI = 0;
	tiny_delay();
}

void uart_send_string(char *dat) {
	char *chr = dat;
	while(*chr != '\0') {
		uart_send_char(*chr);
		++chr;
	}
}

void _uart_interrupt() interrupt 4 {
	uart_stop();
	if(RI) {
		RI = 0;
		uart_recv(SBUF);
	}
	uart_start();
}
