// Variabele aanmaken voor de temperatuurmeter
// Temperatuurmeter op analoog zetten zodat de waarde kan verschillen
const int tempMeter = A5;

// Variabele aanmaken voor de temperatuur
float temperatuur = 0;
 
void setup(){
  pinMode(tempMeter, INPUT);
  
  // Serial aanzetten voor output
  Serial.begin(9600);
}
 
void loop(){
    temperatuur = map(analogRead(tempMeter), 0, 1023, 0, 200);
    
    //Print de temperatuur
    Serial.print("Temperatuur = ");
    Serial.print(temperatuur);
    Serial.print("*C");
    Serial.println();
    
    // Even wachten voor de termperatuur opnieuw wordt opgenomen
    delay(500); 
}
