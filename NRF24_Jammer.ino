//NRF24L01 + ESP32

//VCC   3.3V
//GND   GND
//CE    GPIO4
//CSN   GPIO5
//SCK   GPIO18
//MOSI  GPIO23
//MISO  GPIO19


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// A code created by ViperFSFA, ONLY FOR ETHICAL USE
// #HackThePlanet

RF24 radio(4, 5); 

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setAutoAck(false); 
  radio.setDataRate(RF24_2MBPS); 
  radio.setPALevel(RF24_PA_MAX); 
  radio.setChannel(40); 
  radio.startListening(); 
  radio.stopListening();
  Serial.println("Bluetooth Jammer Active!");
}

void loop() {
  
  uint8_t noise[32];
  for (int i = 0; i < 32; i++) {
    noise[i] = random(256); 
  }
  radio.write(&noise, sizeof(noise)); 
  delayMicroseconds(100); 
}
