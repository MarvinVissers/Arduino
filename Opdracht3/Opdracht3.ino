// Array met alle ledPins
const int ledPins[] = {7, 8, 9, 10, 11, 12, 13};

// Variabele voor de potmeter
const int potMeter = A5;

// Variabele voor de potmeter waarde
int potMeterWaarde = 0;

void setup() {
  // Pins aan de variabele koppelen
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Potmeter aan variabele koppelen
  pinMode(potMeter, INPUT);
}

void loop() {
  // Potmeterwaarde uitlezen
  potMeterWaarde = analogRead(map(potMeter, 0, 1023, 0, 700));

  // Als de waarde hoger of gelijk is aan 0 eerste lamp aanzetten
  if(potMeterWaarde >= 0) {
    digitalWrite(ledPins[0], HIGH);
  } else {
    // Eerste lamp uitzetten
    digitalWrite(ledPins[0], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 100 tweede lamp aanzetten
  if(potMeterWaarde >= 100) {
    digitalWrite(ledPins[1], HIGH);
  } else {
    // Tweede lamp uitzetten
    digitalWrite(ledPins[1], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 200 derde lamp aanzetten
  if(potMeterWaarde >= 200) {
    digitalWrite(ledPins[2], HIGH);
  } else {
    // Derde lamp uitzetten
    digitalWrite(ledPins[2], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 300 vierde lamp aanzetten
  if(potMeterWaarde >= 300) {
    digitalWrite(ledPins[3], HIGH);
  } else {
    // Vierde lamp uitzetten
    digitalWrite(ledPins[3], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 400 vijfde lamp aanzetten
  if(potMeterWaarde >= 400) {
    digitalWrite(ledPins[4], HIGH);
  } else {
    // Vijfde lamp uitzetten
    digitalWrite(ledPins[4], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 500 zesde lamp aanzetten
  if(potMeterWaarde >= 500) {
    digitalWrite(ledPins[5], HIGH);
  } else {
    // Zesde lamp uitzetten
    digitalWrite(ledPins[5], LOW);  
  }

  // Als de waarde hoger of gelijk is aan 600 sevende en laatste lamp aanzetten
  if(potMeterWaarde >= 600) {
    digitalWrite(ledPins[6], HIGH);
  } else {
    // Zevende en laatste lamp uitzetten
    digitalWrite(ledPins[6], LOW);  
  }
}
