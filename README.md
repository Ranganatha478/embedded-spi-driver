---

# 🖧 SPI Driver Development in Embedded C

This project demonstrates the design and implementation of a **modular SPI driver** using Embedded C.  
The driver simulates register-level communication between SPI Master and Slave devices, similar to how SPI peripherals operate in real microcontrollers.

The objective is to showcase **core embedded driver development concepts** such as register manipulation, modular firmware design, and peripheral communication.

---

## 📂 Project Architecture

The project follows a **layered embedded firmware architecture**:

```
Application Layer → Uses the SPI driver APIs
Driver Layer      → Implements SPI functionality
HAL Layer         → Simulates hardware registers
```

Flow:

```
Application
↓
SPI Driver (spi.c)
↓
SPI Registers (spi_registers.c)
↓
Simulated Hardware Peripheral
```

### Directory Structure

```
spi_driver_project/
├── include/
│   ├── spi.h
│   └── spi_registers.h
│
├── src/
│   ├── spi.c
│   ├── spi_registers.c
│   └── main.c
│
├── Makefile
└── README.md
```

---

## 🔄 SPI Communication Flow

SPI (Serial Peripheral Interface) is a **full-duplex communication protocol** used in microcontrollers.

### Signals

| Signal | Description              |
|--------|--------------------------|
| MOSI   | Master Out Slave In      |
| MISO   | Master In Slave Out      |
| SCLK   | Serial Clock             |
| SS     | Slave Select             |

### Communication Sequence

**Master:**
1. Initialize SPI peripheral  
2. Write data to SPI Data Register  
3. Generate clock signal  
4. Transmit data via MOSI  
5. Receive response via MISO  
6. Store data in RX register  

**Slave:**
- Responds to Master via MISO  

---

## ⚙️ Embedded Driver Design

### 1. Register Simulation

Registers are simulated using a structure:

```c
typedef struct
{
    uint32_t CR1;   // Control Register
    uint32_t SR;    // Status Register
    uint32_t DR;    // Data Register
} SPI_TypeDef;
```

| Register | Function                         |
|----------|----------------------------------|
| CR1      | Control register (configuration) |
| SR       | Status register                  |
| DR       | Data register                    |

---

### 2. Bit Manipulation

Configuration uses bit-level operations:

```c
#define SPI_CR1_ENABLE   (1 << 6)
#define SPI_CR1_MASTER   (1 << 2)
#define SPI_CR1_CPOL     (1 << 1)
#define SPI_CR1_CPHA     (1 << 0)
```

---

### 3. Driver APIs

| API              | Function               |
|------------------|------------------------|
| `SPI_Init()`     | Initialize SPI         |
| `SPI_SendData()` | Transmit data          |
| `SPI_ReceiveData()` | Receive data        |

**Example:**

```c
SPI_Init(0);
SPI_SendData(55);
SPI_ReceiveData();
```

---

### 4. Build Instructions

```bash
# Compile
make

# Run
make run

# Clean build files
make clean
```

---

### 5. Example Output

```
SPI Initialized
SPI Sent: 55
SPI Received: 55
```

---

## 🛠️ Technologies Used

- Embedded C  
- GCC Toolchain  
- Makefile  
- Linux / Unix Build System  

---

## 🎯 Learning Outcomes

- Embedded C driver development  
- Register-level peripheral programming  
- Bit manipulation techniques  
- Modular firmware architecture  
- Build automation using Makefile  

---

## 🚀 Future Improvements

- Interrupt-driven SPI communication  
- DMA-based SPI transfer simulation  
- Support for multiple SPI peripherals  
- Integration with RTOS  

---

## 👨‍💻 Author

**Ranganatha Chawan**  
🔗 GitHub: [Ranganatha478](https://github.com/Ranganatha478)

Would you like me to also design a **diagram (visual flowchart)** of the SPI communication sequence so your README has both text and visuals?
