# Serial Interactor

This is the device of serial interactor:

![avatar](https://cdn.jsdelivr.net/gh/mmdjiji/serial-interactor@main/assets/device.jpg)

Of course, the pattern on the back is [Rem(レム)](https://ja.wikipedia.org/wiki/Re:%E3%82%BC%E3%83%AD%E3%81%8B%E3%82%89%E5%A7%8B%E3%82%81%E3%82%8B%E7%95%B0%E4%B8%96%E7%95%8C%E7%94%9F%E6%B4%BB#%E3%82%A8%E3%83%9F%E3%83%AA%E3%82%A2%E9%99%A3%E5%96%B6), who is my wife.

## Usage

You can try to download [hello_world.hex](demo/hello_world.hex) for you device. Maybe you need to use the tool: [stc-isp](tools/stc-isp.exe).

If you can not open the port, install the driver first, the installation package is [CH341SER.EXE](tools/CH341SER.EXE).

## Uart Header File
You can use this library to achieve serial interface interaction, even if you don't understand the principle. Maybe you can read an example first. Use the following code to include it.

```c
#include "uart.h"
```
### Listen
Use the following code to listen uart data on baud rate `9600`:
```c
uart_listen(11059200, 9600);
```
The first parameter is the crystal frequency, usually `11059200` for `11.0592MHz`. The second parameter is the baud rate, you can use `9600` and so on.

### Receive Data
Write `void uart_recv(char dat);` function to receive data, the parameter is a `char`, so it means if you are going to receive a string, you will receive every char of the string. So you may need to create a buffer to store the char, and parse the buffer when end. You can use `\0` to present end, or use `\r\n` to present end, it's up to you.

But please note, don't make this function too slow. Due to its `interrupt` method, too slow will lost information.

An example:
```c
void uart_recv(char dat) {
	if(dat == 'a') {
		flag = 1;
	} else {
		flag = 0;
	}
}
```

### Send Data
There are two functions for sending data, the first is for sending a char, the second is for sending a string, you can have a try.
```c
void uart_send_char(char dat);
void uart_send_string(char *dat);
```

There are other functions in [uart.h](src/uart.h), if you are interested in, read it!

## License
Author: [mmdjiji(JiJi)](https://mmdjiji.com). Open source by [GNU GPLv3.0](https://choosealicense.com/licenses/gpl-3.0/) license.
