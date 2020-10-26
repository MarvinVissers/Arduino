// Ophalen van Servo moter library
#include<Servo.h>

// Aanmaken van variabele voor de knoppen
const int knop1 = 13;
const int knop2 = 12;

// Variabele voor de servor motor
Servo servoMotor;

// Variabele voor de statussen
int statusKnop1 = LOW;
int statusKnop2 = LOW;

void setup() {
  // Knoppen aan de variabele koppelen
  pinMode(knop1, INPUT);
  pinMode(knop2, INPUT);

  // Servo motor aan de variabele koppelen
  servoMotor.attach(3);

  Serial.begin(9600);
}

void loop() {
  // Statussen van de knoppen ophalen
  statusKnop1 = digitalRead(knop1);
  statusKnop2 = digitalRead(knop2);

  Serial.println(statusKnop1);
  Serial.println(statusKnop1);

  // Kijken of knop 1 alleen is ingedrukt
  if (statusKnop1 == HIGH && statusKnop2 == LOW){
    // Servo in 1 seconde heen laten gaan, dan in 1 seconde terug
    servoLoop(8,0);
  }

  // Kijken of alleen knop 2 is ingedrukt
  if (statusKnop1 == LOW && statusKnop2 == HIGH){
    // Servo in 0.5 seconde heen laten gaan, dan in 0.5 seconde terug
    servoLoop(4,0);
  }

  // Kijken of allebei de knoppen ingedrukt zijn
  if (statusKnop1 == HIGH && statusKnop2 == HIGH){
    // Servo in 1 seconde heen laten draaien, 2 seconde wachten en dan in 1 seconde terug
    servoLoop(8, 2000);
  }

  // Als er geen knoppen ingedrukt zijn dan de servo resetten
  else{
    servoMotor.write(0);
  }
}

/**
 * Functie om de servo motor heen en weer te laten lopen met een variabele voor de snelheid en de tussenstops
 * 
 * @param snelheid de snelheid waarmee de servo boven/terug gaat
 * @param tussenstop de delay voordat de terug gaat
 */
void servoLoop (int snelheid, int tussenstop) {
  // Servo naar boven laten gaan
  for (int positie = 0; positie < 120; positie++) {
    // Positie veranderen
    servoMotor.write(positie);
    // Even wachten voordat de loop verder gaat
    delay(snelheid);
  }

  // Delay voordat de servo terug loopt
  delay(tussenstop);

  // Servo terug naar beneden laten lopen
  for (int positie = 120; positie > 0; positie--){
    // Positie veranderen
    servoMotor.write(positie);
    // Even wachten voordat de loop verder gaat
    delay(snelheid);
  }
 }
