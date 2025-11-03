#include <Arduino.h>
#include <string.h> 

void att1(); 
void att2(); 
void att3(); 
void att4(); 

bool estado = false; 

void setup() {
  Serial.begin(9600); 
  att2(); 
  att3(); 
  att4(); 
  Serial.println("Escreva o comando: ");
}

void loop() {
  att1();
}

/*1 - O usuário digita um texto pelo (ex: "LED ON" ou "LED OFF").
Se o texto terminar com "ON" → exiba: LIGAR LED
Se terminar com "OFF" → exiba: DESLIGAR LED
Caso contrário → exiba: COMANDO INVÁLIDO*/

void att1() {
  if (Serial.available() > 0) {
    String texto = Serial.readStringUntil('\n');
    texto.trim(); 

    if (texto.length() > 0) {
      if (texto.endsWith("ON")) {
        Serial.println("Ligar Led");
        estado = true; 
      } else if (texto.endsWith("OFF")) {
        Serial.println("Desligar Led");
        estado = false; 
      } else {
        Serial.println("Comando Ivalido");
      }

      Serial.printf("Voce digitou: %s\n", texto.c_str());

      if (estado) {
        Serial.printf("Estado atual é ligado");
      } else {
        Serial.printf("Estado atual é desligado");
      }
    }
  }
}

/*2 - Converter texto misto e extrair número
String mensagem = "Temperatura = 27C";
Extraia somente o número Converta para inteiro
Exiba o valor convertido para Fahrenheit*/

void att2() {
  
  String comandoUser = "Temperatura = 27C";
  int startIndex = comandoUser.indexOf('=') + 1;
  int endIndex = comandoUser.indexOf('C');
  String numeroString = comandoUser.substring(startIndex, endIndex);
  numeroString.trim();
  int temperaturaCelsius = numeroString.toInt();
  float temperaturaFahrenheit = (temperaturaCelsius * 9.0 / 5.0) + 32.0;


  Serial.print("Valor em Fahrenheit: ");
  Serial.print(temperaturaFahrenheit);
  Serial.println(" F");
}

/*3 - Detectar palavra dentro da frase (char[])  
char frase[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
Verifique se a palavra "ARDUINO" está presente.
Se sim, exiba:
CONTEÚDO RELACIONADO A ARDUINO DETECTADO
Caso contrário:
NÃO ENCONTRADO*/

void att3() {  
  char frase[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
  char* keyword = "ARDUINO";

  Serial.print("Frase: ");
  Serial.println(frase);

  if (strstr(frase, keyword) != NULL) {
    Serial.println("Conteudo Relacionado a Arduino detectado");
  } else {
    Serial.println("Nao encontrado");
  }
}

/*4 - Alternar maiúsculas e minúsculas   
String frase = "sEnAi eSp32 ArDuInO";
Transforme para tudo maiúsculo → exiba
Depois transforme para tudo minúsculo → exiba
Depois transforme deixando apenas a primeira letra maiúscula  → exiba*/

void att4() {  
  String inputUsuario = "sEnAi eSp32 ArDuInO";
  Serial.print("Original: ");
  Serial.println(inputUsuario);

  inputUsuario.toUpperCase();
  Serial.print("Maiúsculo: ");
  Serial.println(inputUsuario);

  inputUsuario.toLowerCase();
  Serial.print("Minúsculo: ");
  Serial.println(inputUsuario);

  if (inputUsuario.length() > 0) {
    String primeiraLetra = inputUsuario.substring(0, 1);
   primeiraLetra.toUpperCase(); 
    
    String restoDaFrase = inputUsuario.substring(1);
    restoDaFrase.toLowerCase();

    inputUsuario = primeiraLetra + restoDaFrase;
  }
  Serial.print("Primeira Maiúscula: ");
  Serial.println(inputUsuario);
}