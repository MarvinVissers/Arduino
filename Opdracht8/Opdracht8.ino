// Ophalen van de IRemote library
#include<IRremote.h>

// Variabele aanmaken voor de resultaten van de afstandingsbediening
decode_results resultaten;

// Variabele voor de teller
int teller = 0;

// Variabele voor de lampen die aanstaan
int ledAan1 = 0;
int ledAan2 = 0;

// Variabele voor de tijd van de loop
unsigned long vorigeTijd = 0;

// Variabele voor de poorten van de ledpins
int ledPins[] = {13, 12, 10, 9};

// Variabele voor de afstandsbediening
int IR = 5;
IRrecv irrecv(IR);

// Variabele voor de knoppen van de afstandingsbediening aanmaken
long int afstandbediening1 = 16582903;
long int afstandbediening2 = 16615543;
long int afstandbediening3 = 16599223;
long int afstandbediening4 = 16591063;

void setup() {
  // LedPins aan de output koppelen
  for (int i = 0; i > 4; i++) {
    // Variabele aan lamp koppelen
    pinMode(ledPins[0], OUTPUT);
  }

  // Serial monitor aanzetten
  Serial.begin(9600);

  // Ontvanger afstandsbediening aanzetten
  irrecv.enableIRIn();
}

void loop() {
  // Ophalen van de statussen van de leds
  int statusLed1 = digitalRead(ledPins[0]);
  int statusLed2 = digitalRead(ledPins[1]);
  int statusLed3 = digitalRead(ledPins[2]);
  int statusLed4 = digitalRead(ledPins[3]);

  // Als de IR Sensor een signaal krijgt dan print serial het resultaat uit en gaat de IR Sensor verder met zoeken naar de resultaten
  if (irrecv.decode(&resultaten)) {
    // Uitprinten van de waarde van de afstandsbediening
    Serial.println(resultaten.value);
    // Verder gaan met resultaten ontvangen
    irrecv.resume();

    // Als er minder dan 2 lampen verbonden zijn dan kunnen er leds aan gekoppeld worden
    if (teller < 2) {
      // Kijken of het resultaat van de eerste knop van de afstandsbediening is
      if (resultaten.value == afstandbediening1 && statusLed1 == LOW) {
        // LedPin onthouden
        onthoudLed(ledPins[0]);
      }

      // Kijken of het resultaat van de tweede knop van de afstandsbediening is
      else if (resultaten.value == afstandbediening2 && statusLed2 == LOW) {
        // LedPin onthouden
        onthoudLed(ledPins[1]);
      }

      // Kijken of het resultaat van de derde knop van de afstandsbediening is
      else if (resultaten.value == afstandbediening3 && statusLed3 == LOW) {
        // LedPin onthouden
        onthoudLed(ledPins[2]);
      }

      // Kijken of het resultaat van de vierde knop van de afstandsbediening is
      else if (resultaten.value == afstandbediening4 && statusLed4 == LOW) {
        // LedPin onthouden
        onthoudLed(ledPins[3]);
      }
    }
  }

  // Als er twee leds gekoppeld zijn voer dan deze code uit
  if (teller == 2) {
    // Kijken of de eerste knop van de afstandsbediening is ingedrukt
    if (resultaten.value == afstandbediening1) {
      // Laat de leds uit en aan gaan om 0.1 seconde
      zetLedKnipperTijd(100);
    }

    // Kijken of de tweede knop van de afstandsbediening is ingedrukt
    if (resultaten.value == afstandbediening2) {
      // Laat de leds uit en aan gaan om 0.2 seconde
      zetLedKnipperTijd(200);
    }
    
    // Kijken of de derde knop van de afstandsbediening is ingedrukt
    if (resultaten.value == afstandbediening3) {
      // Laat de leds uit en aan gaan om 0.3 seconde
      zetLedKnipperTijd(300);
    }

    // Kijken of de vierde knop van de afstandsbediening is ingedrukt
    if (resultaten.value == afstandbediening4) {
      // Laat de leds uit en aan gaan om 0.4 seconde
      zetLedKnipperTijd(400);
    }
  }
}

/**
 * Functie om de led 1 of 2 leds te onthouden
 * 
 * @param ledPin de pin van de led, deze waarden komen uit de array ledPins
 */
void onthoudLed(int ledPin) {
  // Meegestuurde led aanzetten
  digitalWrite(led, HIGH);

  // Als ledAan1 nog niet gekoppeld is de led eraan koppelen, anders aan ledAan2
  if (ledAan1 == 0) {
    // LedPin aan de ledAan1 koppelen
    ledAan1 = ledPin;

    // Teller updaten met een extra led
    teller++;
  } else {
    // LedPin aan de ledAan1 koppelen
    ledAan2 = ledPin;
    // Teller updaten met een extra led
    teller++;
  }
}

/**
 * Functie om de leds te laten knipper met de meegestuurde waarde
 * Deze leds knipperen dan met behulp van millis
 * 
 * @param tijd de tijd tussen het knipperen in millis
 */
void zetLedKnipperTijd(int tijd) {

  // Variabele aanmaken voor de huidige tijd
  unsigned long tijdNu = millis();
  
  // Variabele voor de actieve leds vullen met de leds in het geheugen
  int actieveLed1 = digitalRead(ledAan1);
  int actieveLed2 = digitalRead(ledAan2);
  
  // Kijken of tijdnu min de vorige tijd meer of gelijk is aan de meegestuurde tijd
  if (tijdNu - vorigeTijd >= tijd) {
    // Meegestuurde tijd is groter

    // Tijd van toen veranderen naar de tijd van nu
    vorigeTijd = tijdNu;

    // Kijken naar de status van de leds en die naar het tegenovergestelde zetten
    if (actieveLed1 == LOW && actieveLed2 == LOW) {
      // Leds waren uit, nu aan zetten
      digitalWrite(actieveLed1, HIGH);
      digitalWrite(actieveLed2, HIGH);
    } else {
      // Leds waren aan, nu uit zetten
      digitalWrite(actieveLed1, LOW);
      digitalWrite(actieveLed2, LOW);
    }
  }
}
