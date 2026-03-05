#include <stdio.h>
#include "spi.h"
#include "spi_registers.h"

void SPI_Init(uint8_t mode)
{
    SPI1.CR1 |= SPI_CR1_ENABLE | SPI_CR1_MASTER;

    if(mode == 1)
        SPI1.CR1 |= SPI_CR1_CPHA;

    printf("SPI Initialized\n");
}

void SPI_SendData(uint8_t data)
{
    SPI1.DR = data;
    SPI1.SR |= SPI_SR_TXE;

    printf("SPI Sent: %d\n", data);
}

uint8_t SPI_ReceiveData()
{
    SPI1.SR |= SPI_SR_RXNE;

    printf("SPI Received: %d\n", SPI1.DR);

    return SPI1.DR;
}