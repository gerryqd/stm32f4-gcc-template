#include <stdbool.h>
#include <stdint.h>

#include <stm32f4xx_conf.h>

#define LED_PIN   GPIO_Pin_14

#define USER_BUTTON_PIN   GPIO_Pin_0

static void led_init(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);
  gpio.GPIO_Mode = GPIO_Mode_OUT;
  gpio.GPIO_Pin = LED_PIN;
  GPIO_Init(GPIOD, &gpio);
}

static void button_init(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);
  gpio.GPIO_Mode = GPIO_Mode_IN;
  gpio.GPIO_Pin = USER_BUTTON_PIN;
  GPIO_Init(GPIOA, &gpio);
}

static bool is_button_pressed(void)
{
  uint8_t pin_status = GPIO_ReadInputDataBit(GPIOA, USER_BUTTON_PIN);
  return pin_status == SET;
}

static void led_on(void)
{
  GPIO_SetBits(GPIOD, LED_PIN);
}

static void led_off(void)
{
  GPIO_ResetBits(GPIOD, LED_PIN);
}

int main(void)
{
  led_init();
  button_init();

  while(1)
  {
    if (is_button_pressed())
    {
      led_on();
    }
    else
    {
      led_off();
    }
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
