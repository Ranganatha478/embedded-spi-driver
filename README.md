# SPI Driver Development in Embedded C

This project demonstrates the design and implementation of a modular SPI driver using Embedded C.  
The driver simulates register-level communication between SPI Master and Slave devices, similar to how SPI peripherals operate in real microcontrollers.

The objective of this project is to demonstrate core embedded driver development concepts such as register manipulation, modular firmware design, and peripheral communication.

---

## Project Architecture

The project follows a layered embedded firmware architecture.

Application Layer → Uses the SPI driver APIs

Driver Layer → Implements SPI functionality

Hardware Abstraction Layer → Simulates hardware registers

Application
↓
SPI Driver (spi.c)
↓
SPI Registers (spi_registers.c)
↓
Simulated Hardware Peripheral

### Directory Structure

spi_driver_project/

├── include/
│ ├── spi.h
│ └── spi_registers.h
│
├── src/
│ ├── spi.c
│ ├── spi_registers.c
│ └── main.c
│
├── Makefile
└── README.md


---

# SPI Communication Flow

SPI (Serial Peripheral Interface) is a full-duplex communication protocol used in microcontrollers.

It uses four main signals:

| Signal | Description |
|------|-------------|
| MOSI | Master Out Slave In |
| MISO | Master In Slave Out |
| SCLK | Serial Clock |
| SS | Slave Select |

### Communication Sequence

SPI Master
|
| 1. Initialize SPI peripheral
|
| 2. Write data to SPI Data Register
|
| 3. Clock signal generated
|
| 4. Data transmitted via MOSI
|
| 5. Slave responds via MISO
|
| 6. Data received and stored in RX register
|
SPI Slave


---

# Embedded Driver Design

The SPI driver is implemented using **modular firmware design principles**.

### 1. Register Simulation

The SPI peripheral registers are simulated using a structure:

```c
typedef struct
{
    uint32_t CR1;
    uint32_t SR;
    uint32_t DR;
} SPI_TypeDef;

These registers represent:

| Register | Function                         |
| -------- | -------------------------------- |
| CR1      | Control register (configuration) |
| SR       | Status register                  |
| DR       | Data register                    |

### 2. Bit Manipulation

Driver configuration uses bit-level operations similar to real microcontroller programming.

Example:

#define SPI_CR1_ENABLE   (1 << 6)
#define SPI_CR1_MASTER   (1 << 2)
#define SPI_CR1_CPOL     (1 << 1)
#define SPI_CR1_CPHA     (1 << 0)

These macros simulate hardware control bits used in embedded peripherals.

### 3. Driver APIs

The SPI driver provides the following APIs:

API	Function
SPI_Init()	Initialize SPI peripheral
SPI_SendData()	Transmit data
SPI_ReceiveData()	Receive data

Example:

SPI_Init(0);

SPI_SendData(55);

SPI_ReceiveData();

### 4. Build Instructions

Compile the project using GCC.

make

Run the program:

make run

Clean build files:

make clean

### 5. Example Output
SPI Initialized
SPI Sent: 55
SPI Received: 55

### 6. Technologies Used

Embedded C
GCC Toolchain
Makefile
Linux / Unix Build System

### 7. Learning Outcomes

This project demonstrates key embedded systems concepts:

• Embedded C driver development
• Register level peripheral programming
• Bit manipulation techniques
• Modular firmware architecture
• Build automation using Makefile

### 8. Future Improvements

Possible enhancements:

• Interrupt driven SPI communication
• DMA based SPI transfer simulation
• Support for multiple SPI peripherals
• Integration with RTOS

Author
Ranganatha Chawan

GitHub:
https://github.com/Ranganatha478