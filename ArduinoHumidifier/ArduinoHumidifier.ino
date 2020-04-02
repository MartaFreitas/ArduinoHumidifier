#include "DHT.h"

#define DHTPIN 3     
#define DHTTYPE DHT11  

#define LED_RED     8
#define LED_GREEN   7
#define LED_BLUE  6
#define RELAY 2

#define THR_NORMAL 27
#define THR_CAUTION 32 // below 32C humiture
#define THR_CAUTION_EXTR 41 // below 41C humiture

// Inicializa o sensor DHT 
DHT dht(DHTPIN, DHTTYPE);

// Variaveis
float humidity, heat_index,  temperature_celsius;
int red, green, blue;


//char c =' ';
void setup() {
  
    Serial.begin(9600);
 
    // configuração dos pinos
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT); 
    pinMode(RELAY, OUTPUT);
  
    //inicia como desligado
    digitalWrite(LED_RED, LOW); 
    digitalWrite(LED_GREEN, LOW);  
    digitalWrite(LED_BLUE, LOW); 

    dht.begin();

    delay(100);
    digitalWrite(RELAY, HIGH);  

     // test the LEDs
     // RED
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    delay(3000);
    // GREEN
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
    delay(3000);
    // BLUE
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
    delay(3000);
    // CIANO
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(3000);
    // PURPLE
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
    delay(3000);
    // YELLOW
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
    delay(3000);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(3000);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    
  delay(1000);
}

void loop() {
    humidity = dht.readHumidity();
    temperature_celsius =dht.readTemperature();
    heat_index = dht.computeHeatIndex(temperature_celsius, humidity, false);

  
    if (isnan(humidity) || isnan(temperature_celsius)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }


    if (heat_index < THR_NORMAL) {
    // no warning, turn on ciano
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(RELAY,HIGH);
    Serial.print("THR_NORMAL \t");

    
    }
    else if (heat_index < THR_CAUTION) {
      // caution, turn on blue LED
        
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(RELAY,LOW);
      Serial.print("THR_CAUTION \t");


    }
    else if (heat_index < THR_CAUTION_EXTR) {
      // extreme caution, turn on purple LED
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(RELAY,LOW);
      Serial.print("THR_CAUTION_EXTR \t");


    }
    else {
      // (extreme) danger, turn on red LED
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(RELAY,LOW);
      Serial.print("EXTREME \t");


    }


    Serial.print("humidity : "); 
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("temperature : "); 
    Serial.print(temperature_celsius);
    Serial.print(" Celsius\t");
    Serial.print("heat index : "); 
    Serial.print(heat_index);
    Serial.println("  Celsius ");
  
  delay(5000);
}
