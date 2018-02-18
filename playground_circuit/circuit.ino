#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>
#include <stdio.h>
#include <serial_interface.h>
#include <neopixel_blit.h>

Pixels pix;
/*const int speaker = 5;*/

void setup() {
  /*pinMode(speaker, OUTPUT);*/
  init_serial_stdio();
  init_neopixel_blit();
  // Turn the Serial Protocol ON
  Serial.begin(9600);
  CircuitPlayground.begin();
}
void loop() {
 int byteRead, i;

 /* check if data has been sent from the computer: */
 if (Serial.available()) {
 
 /* read the most recent byte */
 byteRead = Serial.parseInt();
 
 //Turn off all LEDs if the byte Read = 0
 if(byteRead==0){
 //Turn off all LEDS 
  for(i = 0; i < 10; i++){
    pix[i][PIX_RED] = 0;
    pix[i][PIX_GRN] = 0;
    pix[i][PIX_BLU] = 0; // set the LED on
  }
  neopixel_blit(pix);
  delay(500);
 
 }
 
 //Turn LED ON depending on the byte Read.
 if(byteRead > 0){
  /*makeTone(speaker, 440, 100);*/
  CircuitPlayground.playTone(740, 500);
  for(i = 0; i < 10; i++){
    pix[i][PIX_RED] = 10;
    pix[i][PIX_GRN] = 0;
    pix[i][PIX_BLU] = 0; // set the LED on
   }
   neopixel_blit(pix);
   delay(1000);
 }
 for(i = 0; i < 10; i++){
    pix[i][PIX_RED] = 0;
    pix[i][PIX_GRN] = 0;
    pix[i][PIX_BLU] = 0; // set the LED on
  }
  neopixel_blit(pix);
  delay(500);
 }
} 

