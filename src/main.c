// main.c
// This file is a part of serial-interactor project.
// For STC8F1K08 device.

// Author: mmdjiji (JiJi)
// GitHub: https://github.com/mmdjiji/serial-interactor

#include <stc8.h>
#include "uart.h"

int flag;

void main() {
	uart_listen(11059200, 9600);
	flag = 0;
	while(1) {
		if(flag)
			uart_send_string("hello world!\r\n");
	}
}

void uart_recv(char dat) {
	if(dat == 'a') {
		flag = 1;
	} else {
		flag = 0;
	}
}