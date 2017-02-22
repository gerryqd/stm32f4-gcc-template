#include "stm32f4xx_it.h"

extern void decrease_tick(void);

void SysTick_Handler(void)
{
  decrease_tick();
}
