#include <stm32f4xx_conf.h>

#include "delay.h"

#define HZ  1000

volatile unsigned int tick_remains = 0;

void decrease_tick(void)
{
  if (tick_remains != 0)
  {
    tick_remains--;
  }
}

void delay_init(void)
{
  if (SysTick_Config(SystemCoreClock / HZ))
  {
    while(1)
    {
    }
  }
}

static void delay_1s(void)
{
  tick_remains = HZ;
  while(tick_remains != 0)
  {
  }
}

void delay_sec(int seconds)
{
  for (int i=0; i<seconds; i++)
  {
    delay_1s();
  }
}
