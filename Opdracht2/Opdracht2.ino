// Aanmaken van variabele voor de lamp en knop
const int ledPin = 11;
const int knopPin = 13;

// Variabele aanmaken voor de teller en de status
int teller = 0;
int statusKnop = 0;

void setup() {
  // Uitgangen aan de knop en lamp koppelen
  pinMode(ledPin, OUTPUT);
  pinMode(knopPin, INPUT);

  // Lamp uitzetten
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Waarde van de knop ophalen
  statusKnop = digitalRead(knopPin);

  // Kijken naar de status van de knop
  if (statusKnop == HIGH) {
    // Teller bijhouden om de lamp uit te zetten
    teller++;
    if (teller % 2 == 0) {
      // Lamp uitzetten
      digitalWrite(ledPin, LOW);
    }
  } else {
    // Lamp uitzetten
    digitalWrite(ledPin, HIGH);
  }
}
