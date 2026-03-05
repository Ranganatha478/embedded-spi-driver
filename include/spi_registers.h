#ifndef SPI_REGISTERS_H
#define SPI_REGISTERS_H

#include <stdint.h>

/* SPI Register Structure */

typedef struct
{
    uint32_t CR1;
    uint32_t SR;
    uint32_t DR;
} SPI_TypeDef;

/* Simulated SPI Peripheral */

extern SPI_TypeDef SPI1;

/* Bit Definitions */

#define SPI_CR1_ENABLE   (1 << 6)
#define SPI_CR1_MASTER   (1 << 2)
#define SPI_CR1_CPOL     (1 << 1)
#define SPI_CR1_CPHA     (1 << 0)

#define SPI_SR_TXE       (1 << 1)
#define SPI_SR_RXNE      (1 << 0)

#endif