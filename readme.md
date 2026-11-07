# STM32 Bare-Metal GPIO Control & LED Sequencing

A register-level GPIO control and LED sequencing project developed using **Bare-Metal Embedded C** on the **STM32C031C6 NUCLEO board**, with hardware simulation in Wokwi.

The project focuses on understanding microcontroller peripheral control through direct memory-mapped register access using CMSIS device definitions, without relying on STM32 HAL GPIO functions.

---

## Project Overview

This project demonstrates low-level GPIO configuration and control using two GPIO ports (GPIOA and GPIOB) to operate 16 LEDs independently and in multiple combinations.

The primary objective is to understand how microcontrollers interact with hardware peripherals at the register level while developing reusable and structured Embedded C code.

## Hardware & Development Environment

| Component | Specification |
|---|---|
| Microcontroller | STM32C031C6 |
| Development Board | NUCLEO-C031C6 |
| Programming Language | Embedded C |
| Programming Approach | Bare-Metal |
| Device Interface | CMSIS |
| Simulation Platform | Wokwi |
| GPIO Ports | GPIOA and GPIOB |
| Total LEDs | 16 |
| Current-limiting Resistors | 330 Ω |

## GPIO Pin Mapping

### GPIOA – LED Group A

| LED | GPIO Pin |
|---|---|
| LEDA1 | PA5 |
| LEDA2 | PA4 |
| LEDA3 | PA7 |
| LEDA4 | PA6 |
| LEDA5 | PA9 |
| LEDA6 | PA3 |
| LEDA7 | PA10 |
| LEDA8 | PA11 |

### GPIOB – LED Group B

| LED | GPIO Pin |
|---|---|
| LEDB1 | PB3 |
| LEDB2 | PB10 |
| LEDB3 | PB6 |
| LEDB4 | PB5 |
| LEDB5 | PB8 |
| LEDB6 | PB7 |
| LEDB7 | PB13 |
| LEDB8 | PB2 |

Each LED is connected in series with a 330 Ω current-limiting resistor. The LED cathode is connected to GND.

## Implemented Features

### 1. Register-Level GPIO Configuration

- Peripheral clock activation through RCC.
- GPIO output configuration using MODER.
- Direct manipulation of GPIO output registers.
- Initialization of GPIOA and GPIOB.

### 2. Bitwise Operations & Macro Abstraction

- Bit shifting for individual GPIO pin selection.
- Bitwise OR operations for combining GPIO masks.
- Macro-based LED definitions.
- Reusable LED group definitions.

### 3. GPIO Control

- Individual LED toggling.
- Explicit LED activation and deactivation.
- Multiple GPIO pin control using bitmasks.
- BSRR-based atomic GPIO set/reset operations.

### 4. LED Sequencing Patterns

- Sequential LED activation.
- Sequential LED deactivation in the same order.
- Odd LED grouping.
- Even LED grouping.
- Individual GPIO port patterns.
- Combined GPIOA and GPIOB control.

## Bare-Metal Programming Approach

This project uses CMSIS device definitions to access STM32 peripheral registers directly.

Instead of relying on high-level HAL GPIO functions such as:

```c
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
```

The project performs register-level operations such as:

```c
GPIOA->BSRR = (1U << 5);
```

This provides direct control over the microcontroller's GPIO peripherals and helps develop a deeper understanding of hardware-level programming.

### Registers Used

| Register | Purpose |
|---|---|
| RCC->IOPENR | Enable GPIO peripheral clocks |
| GPIOA->MODER | Configure GPIOA pin modes |
| GPIOB->MODER | Configure GPIOB pin modes |
| GPIOA->ODR | Read GPIOA output states |
| GPIOB->ODR | Read GPIOB output states |
| GPIOA->BSRR | Set/reset GPIOA pins |
| GPIOB->BSRR | Set/reset GPIOB pins |

## Project Structure

```text
STM32-Bare-Metal-GPIO/
│
├── Core/
│   └── Src/
│       └── main.c
│
├── diagram.json
│
└── README.md
```

The `main.c` file contains GPIO initialization, LED control functions, delay routines and sequencing patterns.

The `diagram.json` file contains the Wokwi circuit configuration.

## Simulation

The project was developed and tested using the Wokwi online simulator.

Simulation platform:

https://wokwi.com/

The simulation allows testing GPIO configuration and LED sequencing without requiring physical hardware during the initial development stage.

## Learning Outcomes

Through this project, I explored:

- Bare-Metal Embedded C programming.
- STM32 peripheral register architecture.
- CMSIS device definitions.
- Memory-mapped I/O.
- GPIO initialization and configuration.
- Bitwise operations and bitmasking.
- Atomic GPIO operations using BSRR.
- Modular and reusable embedded C functions.

## Future Improvements

- Hardware timer-based delays.
- Interrupt-driven GPIO control.
- Clock configuration and optimization.
- UART communication.
- SPI and I2C peripheral integration.
- Modular GPIO driver development.
- Transition towards more complex embedded applications.

## Project Information

**Platform:** STM32 NUCLEO-C031C6  
**Language:** Embedded C  
**Programming Style:** Bare-Metal Register-Level Programming  
**Hardware Interface:** CMSIS  
**Simulation:** Wokwi

---

*This project is part of my journey towards understanding low-level microcontroller programming and developing a strong foundation in embedded systems and firmware engineering.*
