/*#include <Arduino.h>

#define pinLed 21
#define pinBotao 23

bool estadoAnteriorBotao = 0;
bool estadoBotao = 0; 
bool estadoLed = 0;

void setup() {
 Serial.begin(9600);

 pinMode(pinLed, OUTPUT);
 
 pinMode(pinBotao, INPUT_PULLUP);
}

void loop() {
 estadoBotao = digitalRead (pinBotao);
  
  //botao clicado
  if (estadoAnteriorBotao == 0 && estadoBotao == 1){
      estadoLed = !estadoLed; //! significa diferente
  }
 
  
  if (estadoLed == 1){
    digitalWrite (pinLed, HIGH);
  }
  else {
    digitalWrite (pinLed, LOW);
  }
  
  
  estadoAnteriorBotao = estadoBotao;
}
*/
//botao 23 e led 21