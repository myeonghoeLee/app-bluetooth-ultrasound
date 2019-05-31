#include <SPI.h>//수신
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>
SoftwareSerial btSerial(2,3);
RF24 radio(7, 8); // CE, SCN
const byte address[6] = "00001";

void setup() {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();

btSerial.begin(9600);
}
void loop() {
if (radio.available()) {
int x;
radio.read(&x, sizeof(x));
Serial.println(x);


delay(100);
if(x<20){
  btSerial.println(1);
}
}
}
