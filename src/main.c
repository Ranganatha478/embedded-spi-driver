#include "spi.h"

int main()
{
    SPI_Init(0);

    SPI_SendData(55);

    SPI_ReceiveData();

    return 0;
}