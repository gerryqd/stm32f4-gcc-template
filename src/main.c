#include <stm32f4xx_conf.h>

#define LED_PIN   GPIO_Pin_14

static void led_init(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);
  gpio.GPIO_Mode = GPIO_Mode_OUT;
  gpio.GPIO_Pin = LED_PIN;
  GPIO_Init(GPIOD, &gpio);
}

static void led_on(void)
{
  GPIO_SetBits(GPIOD, LED_PIN);
}

static void led_off(void)
{
  GPIO_ResetBits(GPIOD, LED_PIN);
}

static void delay(void)
{
  for (volatile unsigned int i=0; i<10000000; i++)
    ;
}

int main(void)
{
  led_init();

  while(1)
  {
    led_on();
    delay();
    led_off();
    delay();
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
  while(1)
  {
  }
}
#endif
