// Aanamken van variabele voor de lampen
const int ledRood = 2;
const int ledOranje = 3;
const int ledGroen = 4;

// Bluetooth variabele
char incoming_value = 0;

// Serial monitor aanzetten en de lampen op de pins zetten
void setup() {
  Serial.begin(9600);
  pinMode(ledRood, OUTPUT);
  pinMode(ledOranje, OUTPUT);
  pinMode(ledGroen, OUTPUT);
}

void loop() {
  // Controleren van de ingevoerde waarde
  if (Serial.available() > 0) {
    // Data opslaan in de incoming value
    incoming_value = Serial.read();

    // Variabele printen in Serial
    Serial.println(incoming_value);
  }

  // Kijken of de waarde 1 is
  if (incoming_value == '1') {
    // Zet de groene lamp aan en de rest uit
    digitalWrite(ledRood, HIGH);
    digitalWrite(ledOranje, LOW);
    digitalWrite(ledGroen, LOW);
  
    // 1 seconden wachten
    delay(12000);

    // Groene lamp uitzetten en orangje aanzetten
    setLights(ledRood, ledOranje);

    // 1 seconden wachten
    delay(6000);

    // Oranje lamp uitzetten en rood aanzetten
    setLights(ledOranje, ledGroen);

    // 1 seconden wachten
    delay(12000);
  } else {
    digitalWrite(ledOranje, HIGH);
    delay(1000);
    digitalWrite(ledOranje, LOW);
    delay(1000);  
  }
}

/**
 * Functie om de lamp te veranderen
 * 
 * led1 is de led die nu aanstaat en uit mag
 * led2 is de led die nu uitstaat en aan mag
 * 
 * Na het uitvoeren doet de functie 
 */
void setLights(int led1, int led2) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
}
