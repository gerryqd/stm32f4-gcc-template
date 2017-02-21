#include <stm32f4xx_conf.h>

void delay(void)
{
  for (volatile unsigned int i=0; i<10000000; i++)
    ;
}

int main (void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  GPIOD->MODER = (1 << 26);

  while (1)
  {
    GPIOD->ODR ^= (1 << 13);
    delay();
  }
}
