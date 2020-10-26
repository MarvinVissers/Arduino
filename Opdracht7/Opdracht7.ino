// Servo motor library importeren
#include <Servo.h>

// Variabele voor de sensor
const int trigPin = 10;
const int echoPin = 9;

// Variabele voor de tijdsduur van de servo
float tijdsduur;

// Variabele voor de afstand van het object
float afstand;

// Variabele voor de servo
Servo mijnServo;

void setup() {
  // Variabele voor de sensor koppelen aan de sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo koppelen aan een pin
  mijnServo.attach(11);

  // Serial monitor starten 
  Serial.begin(9600);
}

void loop() {
  // Geluid uitzetten om te testen hoelang het duurt voordat het weerkaast wordt
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Tijdsduur bereken
  tijdsduur = pulseIn(echoPin, HIGH);

  // Afstand bereken
  afstand = tijdsduur / 58;

  // Astand in de serial monitor zetten
  Serial.print("Afstand: ");
  Serial.print(afstand);
  Serial.println("cm");
  delay(100);

  // Afstand uitlezen en neerzetten in de servo
  int mapWaarde = map(afstand, 4 , 10, 0, 180);
  mijnServo.write(mapWaarde);

  // Even wachten
  delay(100);
}
