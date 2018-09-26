#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
SSD1306Wire  display(0x3c, 21, 22);
int freq = 5000;
int ledchannel = 0;
int resolution = 8;
int rd;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
  Serial.println();
  Serial.println();
ledcSetup(ledchannel,freq,resolution);
//ledcAttachPin(LED_BUILTIN,ledchannel);
pinMode(39,INPUT);

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);


  
}

void loop() {
  // put your main code here, to run repeatedly:
  rd=analogRead(39);
    Serial.println(rd);
    rd=map(rd,0,4000,0,255);
    ledcWrite(ledchannel,rd);
    delay(7);
   display.clear();
   display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Read Value is:");
    display.drawString(0, 20, String(rd));
    display.display();
    delay(10);
}
