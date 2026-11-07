#include "stm32c0xx.h"
#include <stdint.h>
#define GPIOAEN (1U << 0)
#define GPIOBEN (1U << 1)
#define LEDA1 (1U << 5)   
#define LEDA2 (1U << 4)   
#define LEDA3 (1U << 7)   
#define LEDA4 (1U << 6)   
#define LEDA5 (1U << 9)   
#define LEDA6 (1U << 3)   
#define LEDA7 (1U << 10)  
#define LEDA8 (1U << 11)  
#define LEDB1 (1U << 3)   
#define LEDB2 (1U << 10)  
#define LEDB3 (1U << 6)   
#define LEDB4 (1U << 5)   
#define LEDB5 (1U << 8)   
#define LEDB6 (1U << 7)   
#define LEDB7 (1U << 13)  
#define LEDB8 (1U << 2)   
#define LEDA_ODD  (LEDA1 | LEDA3 | LEDA5 | LEDA7)
#define LEDA_EVEN (LEDA2 | LEDA4 | LEDA6 | LEDA8)
#define LEDA_ALL  (LEDA_ODD | LEDA_EVEN)
#define LEDB_ODD  (LEDB1 | LEDB3 | LEDB5 | LEDB7)
#define LEDB_EVEN (LEDB2 | LEDB4 | LEDB6 | LEDB8)
#define LEDB_ALL  (LEDB_ODD | LEDB_EVEN)
void GPIO_Init(void)
{
    RCC->IOPENR |= (GPIOAEN | GPIOBEN);

    GPIOA->MODER &= ~((3U << 10)|(3U << 8)|(3U << 14)|(3U << 12)|(3U << 18)|(3U << 6)|(3U << 20)|(3U << 22)
    );

    GPIOA->MODER |= (
        (1U << 10) |(1U << 8)|(1U << 14)|(1U << 12)|(1U << 18)|(1U << 6)|(1U << 20)|(1U << 22)
    );

    GPIOB->MODER &= ~((3U << 6)|(3U << 20)|(3U << 12)|(3U << 10)|(3U << 16)|(3U << 14)|(3U << 26)|(3U << 4)
    );

    GPIOB->MODER |= (
        (1U << 6)  |(1U << 20)|(1U << 12)|(1U << 10)|(1U << 16)|(1U << 14)|(1U << 26)|(1U << 4)
    );

    
    GPIOA->BSRR = (LEDA_ALL << 16U);
    GPIOB->BSRR = (LEDB_ALL << 16U);
}
void GPIOA1(uint32_t Led)
{
    if ((GPIOA->ODR & Led) == 0U)
    {
        GPIOA->BSRR = Led;
    }
    else
    {
        GPIOA->BSRR = (Led << 16U);
    }
}

void GPIOB1(uint32_t Led)
{
    if ((GPIOB->ODR & Led) == 0U)
    {
        GPIOB->BSRR = Led;
    }
    else
    {
        GPIOB->BSRR = (Led << 16U);
    }
}
void Delay(void)
{
    for (volatile uint32_t i = 0; i < 200000; i++)
    {
        __NOP();
    }

}
void GPIOA_OFF(uint32_t Led){
    GPIOA->BSRR = (Led << 16U);
  }
void GPIOB_OFF(uint32_t Led){
    GPIOB->BSRR = (Led << 16U);
  }  
void pattern1(){
    
        GPIOA1(LEDA1);
        Delay();

        GPIOB1(LEDB1);
        Delay();

        GPIOA1(LEDA2);
        Delay();

        GPIOB1(LEDB2);
        Delay();

        GPIOA1(LEDA3);
        Delay();

        GPIOB1(LEDB3);
        Delay();

        GPIOA1(LEDA4);
        Delay();

        GPIOB1(LEDB4);
        Delay();
        GPIOA1(LEDA5);
        Delay();

        GPIOB1(LEDB5);
        Delay();

        GPIOA1(LEDA6);
        Delay();

        GPIOB1(LEDB6);
        Delay();

        GPIOA1(LEDA7);
        Delay();

        GPIOB1(LEDB7);
        Delay();

        GPIOA1(LEDA8);
        Delay();

        GPIOB1(LEDB8);
        Delay();
      };

void pattern2(){
    
        GPIOA_OFF(LEDA1);
        Delay();

        GPIOB_OFF(LEDB1);
        Delay();

        GPIOA_OFF(LEDA2);
        Delay();

        GPIOB_OFF(LEDB2);
        Delay();

        GPIOA_OFF(LEDA3);
        Delay();

        GPIOB_OFF(LEDB3);
        Delay();

        GPIOA_OFF(LEDA4);
        Delay();

        GPIOB_OFF(LEDB4);
        Delay();
        GPIOA_OFF(LEDA5);
        Delay();

        GPIOB_OFF(LEDB5);
        Delay();

        GPIOA_OFF(LEDA6);
        Delay();

        GPIOB_OFF(LEDB6);
        Delay();

        GPIOA1(LEDA7);
        Delay();

        GPIOB_OFF(LEDB7);
        Delay();

        GPIOA_OFF(LEDA8);
        Delay();

        GPIOB_OFF(LEDB8);
        Delay();
      };

int main(void)
{
    GPIO_Init();

    while (1)
    {   
        pattern1();
        Delay();
        pattern2();
        Delay();
        GPIOA1(LEDA1);
        Delay();

        GPIOB1(LEDB1);
        Delay();

        GPIOA1(LEDA3);
        Delay();

        GPIOB1(LEDB3);
        Delay();

        GPIOA1(LEDA5);
        Delay();

        GPIOB1(LEDB5);
        Delay();

        GPIOA1(LEDA7);
        Delay();

        GPIOB1(LEDB7);
        Delay();

        GPIOA1(LEDA_ODD);
        Delay();

        GPIOB1(LEDB_ODD);
        Delay();

        GPIOA1(LEDA_EVEN);
        Delay();

        GPIOB1(LEDB_EVEN);
        Delay();

        GPIOA1(LEDA_ALL);
        Delay();

        GPIOB1(LEDB_ALL);
        Delay();
       };
    
}
