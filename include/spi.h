#ifndef SPI_H
#define SPI_H

#include <stdint.h>

void SPI_Init(uint8_t mode);
void SPI_SendData(uint8_t data);
uint8_t SPI_ReceiveData(void);

#endif