/*#include <Arduino.h>
#include <Bounce2.h>

Bounce botao = Bounce();

#define pinLed 21
#define pinBotao 23

bool estadoAnteriorBotao = 0;
bool estadoBotao = 0; 
bool estadoLed = 0;

void setup() {
 Serial.begin(9600);

 pinMode(pinLed, OUTPUT);
 botao.attach( 23 ,  INPUT_PULLUP ); //substitui pinmode

}

void loop() {

  botao.update(); //digitalRead*/

 // Serial.println(botao.fell()); //pressionado - retorna true quando botao for pressionado no exato momento que aperta

 // Serial.println(botao.read()); //le o botao e retorna a leitura

 // Serial.println(botao.rose()); //retorna true quando botao for solto

 // Serial.println(botao.changed()); //retorna true quando existe uma alteracao

 // Serial.println(botao.currentDuration()); //retorna tempo do estado atual do botao

 // Serial.println(botao.previousDuration()); //retorna tempo do estado anterior do botao
  
