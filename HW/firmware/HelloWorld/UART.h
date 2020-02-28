#ifndef UART_h
#define UART_h

class UART {
  public:
    void UARTInit(int baud);
    void UARTTXLorem();
    void UARTTXSS2018();
    void UARTTX(char* data);
};
#endif
