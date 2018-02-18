/* This program was created by ScottC on 8/5/2012 to receive serial 
signals from a computer to turn on/off 1-9 LEDs */

void setup() { 
 // initialize the digital pins as an output.
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT);
// Turn the Serial Protocol ON
 Serial.begin(9600);
}

void loop() {
 int byteRead;

 /* check if data has been sent from the computer: */
 if (Serial.available()) {
 
 /* read the most recent byte */
 byteRead = Serial.parseInt();
 //You have to subtract '0' from the read Byte to convert from text to a number.
 
 //Turn off all LEDs if the byte Read = 0
 if(byteRead==0){
 //Turn off all LEDS 
 analogWrite(3, 0);
 delay(1000);
 
 }
 
 //Turn LED ON depending on the byte Read.
 if(byteRead > 0){
 analogWrite(3, 100); // set the LED on
 delay(1000);
 }
 }
 }
