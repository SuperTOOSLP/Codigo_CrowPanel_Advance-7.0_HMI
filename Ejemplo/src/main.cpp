#include <lvgl.h>
#include <lgfx.h>
#include <demos/lv_demos.h>
#include "ui/ui.h"

/* extensions io */
#include <TCA9534.h>
TCA9534 ioex;
void setup()
{

  pinMode(8, OUTPUT); // buzzer
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);

  Serial.begin(115200);

  Wire.begin(15, 16);
  delay(50);

  ioex.attach(Wire);
  ioex.setDeviceAddress(0x18);
  ioex.config(1, TCA9534::Config::OUT);
  ioex.config(2, TCA9534::Config::OUT);
  ioex.config(3, TCA9534::Config::OUT);
  ioex.config(4, TCA9534::Config::OUT);

  ioex.output(1, TCA9534::Level::H);

  ioex.output(3, TCA9534::Level::L);
  ioex.output(4, TCA9534::Level::H);

  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  ioex.output(2, TCA9534::Level::L);
  delay(20);
  ioex.output(2, TCA9534::Level::H);
  delay(100);
  pinMode(1, INPUT);
  /*end*/

  lcd.setup();
  // lv_demo_widgets();



  ui_init();
}

void loop()
{
  delay(lv_timer_handler());
}
