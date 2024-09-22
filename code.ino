#include <Servo.h>  // Inclua a biblioteca Servo

// Defina os pinos para os componentes
const int servoPin1 = 12;
const int servoPin2 = 13;
const int buzzerPin = 10;
const int pirPin = 4;
const int ledPin = 6;

// Crie os objetos Servo
Servo servo1;
Servo servo2;

void setup() {
  // Inicialize o LED como saída
  pinMode(ledPin, OUTPUT);
  
  // Inicialize o buzzer como saída
  pinMode(buzzerPin, OUTPUT);
  
  // Inicialize o pino do sensor PIR como entrada
  pinMode(pirPin, INPUT);
  
  // Configure os servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  
  // Inicialize os servos em uma posição inicial
  servo1.write(0); // Ângulo inicial do servo1
  servo2.write(0); // Ângulo inicial do servo2
  
  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);
}

void loop() {
  int pirValue = digitalRead(pirPin); // Lê o valor do sensor PIR

  if (pirValue == 1) {
    // Se o sensor detectar movimento
    digitalWrite(ledPin, HIGH);   // Liga o LED
    tone(buzzerPin, 1000);        // Emite um som de 1000 Hz
    servo1.write(180);            // Posiciona o servo1 a 120 graus
    servo2.write(0);             // Posiciona o servo2 a 60 graus
    Serial.println(pirValue);
  } else {
    // Se não houver movimento
    digitalWrite(ledPin, LOW);    // Desliga o LED
    noTone(buzzerPin);           // Para o som
    servo1.write(120);             // Posiciona o servo1 a 0 graus
    servo2.write(60);             // Posiciona o servo2 a 0 graus
    Serial.println("Sem movimento.");
  }

  delay(500); // Aguarda 500 milissegundos para evitar leitura excessiva
}
