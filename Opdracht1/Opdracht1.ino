// Aanmaken van een array met alle ingangen
const int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6};

// Alle ingangen koppelen aan de array 
void setup() {
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);
  pinMode(ledPins[4], OUTPUT);
  pinMode(ledPins[5], OUTPUT);
  pinMode(ledPins[6], OUTPUT);
  pinMode(ledPins[7], OUTPUT);
}

void loop() {
  // De lampjes van links naar rechts laten gaan
  for(int i = 0; i < 8; i++) {
    // Lampje aanzetten, 0.6s wachten en dan uit zetten
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }

  // de lampjes terug van rechts naar links laten gaan
  for(int i = 8; i > 0; i--) {
    // Lampje aanzetten, 0.6s seconden wachten en dan uit zetten
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }
}
