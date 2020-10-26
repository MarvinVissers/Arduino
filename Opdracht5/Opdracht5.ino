// Array aanmaken in de vorm van Rood, Groen, Blauw
const int ledRed = 11;
const int ledGroen = 9;
const int ledBlauw = 10;

//Maak de voor de waardes van de kleuren
int roodWaarde; 
int groenWaarde; 
int blauwWaarde; 

void setup() {
  // Leds koppelen aan de pins
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Rode lamp aanzetten 
  analogWrite(ledRed, HIGH);
}

void loop() {
  // Kleuren goedzetten
  roodWaarde = 255;
  groenWaarde = 0;
  blauwWaarde = 0;
  
  
    // For loop voor alle rode kleuren
    for (int i = 0; i < 255; i++) {
      // Variabele veranderen
      roodWaarde--;
      groenWaarde++;
      
      // Functie voor kleur aanspreken
      veranderKleur(roodWaarde, groenWaarde, blauwWaarde);
    }
  
    // Kleuren goedzetten
    roodWaarde = 0;
    groenWaarde = 255;
    blauwWaarde = 0;
    
    // For loop voor alle groene kleuren
    for (int i = 0; i < 255; i++) {
        // Variabele veranderen
        groenWaarde--;
        blauwWaarde++;
      
        // Functie voor kleur aanspreken
        veranderKleur(roodWaarde, groenWaarde, blauwWaarde);
    }

    // Kleuren goedzetten
    roodWaarde = 0;
    groenWaarde = 0;
    blauwWaarde = 255;
      
    // For loop voor alle groene kleuren
    for (int i = 0; i < 255; i++) {
      // Variabele veranderen
      blauwWaarde--;
      roodWaarde++;
      
      // Functie voor kleur aanspreken
      veranderKleur(roodWaarde, groenWaarde, blauwWaarde);
    }
}

/**
 * Functie om de kleur te veranderen
 * 
 * @param rood staat voor rood (0 tot 255)
 * @param groen staat voor groen (0 tot 255)
 * @param blauw staat voor blauw (0 tot 255)
 */
void veranderKleur(int rood, int groen, int blauw) {
    // Door de pins heen lopen en de waarde zetten
  for (int i = 0; i < 3; i++) {
      // Kleuren waardes neezetten
      analogWrite(ledRed, rood);
      analogWrite(ledGroen, groen);
      analogWrite(ledBlauw, blauw);
      // Even wachten
      delay(5);
    }
}
