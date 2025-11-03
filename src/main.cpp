#include <Arduino.h>
#include <Bounce2.h>

const int pinLed = 21;
const int pinBotaoAumenta = 23;
const int pinBotaoDiminui = 22;

int luzIntensidade = 0; // Nível de 0 a 100

Bounce botao1 = Bounce();
Bounce botao2 = Bounce();

void setup() {
   Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  
  digitalWrite(pinLed, LOW); 

  botao1.attach(pinBotaoDiminui, INPUT_PULLUP);
  botao1.interval(25);
  botao2.attach(pinBotaoAumenta, INPUT_PULLUP);
  botao2.interval(25);

 Serial.println("Controle o brilho com os botões.");
}

void loop() {

  botao1.update();
  botao2.update();

  if (botao1.fell()) {
    if (luzIntensidade < 100) {
      luzIntensidade += 10;
    }
  }

  if (botao2.fell()) {
    if (luzIntensidade > 0) {
      luzIntensidade -= 10;
    }
  }

  int valorBrilho = map(luzIntensidade, 0, 100, 0, 255);

  analogWrite(pinLed, valorBrilho);

  Serial.print("Intensidade: ");
  Serial.print(luzIntensidade);
  Serial.print("%  -> Valor PWM: ");
  Serial.println(valorBrilho);
  
  delay(20); 
  
}