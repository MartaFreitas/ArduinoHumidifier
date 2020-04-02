#include "DHT.h"

// Sensor humity and temperature 
#define DHTPIN 3     
#define DHTTYPE DHT11  



int ledRed =6;
int ledGreen =7;
int ledBlue =8;
int canalRele =2;



// Conecte pino 1 (esquerda do sensor) no +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Conecte o pino 2 do sensor onde setou o pino DHT
// Conecte o pino 4 (direita do sensor) no GROUND
// Conecte um resistor 10K  no pino 2 (data) com o pino 1 (alimentação) do sensor

// Inicializa o sensor DHT 
DHT dht(DHTPIN, DHTTYPE);

char c =' ';


void setup() {
  Serial.begin(9600);
 
    // configuração dos pinos
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledBlue, OUTPUT); 
    pinMode(canalRele, OUTPUT);
  
  //inicia como desligado
   digitalWrite(ledRed, HIGH); 
   digitalWrite(ledGreen, HIGH);  
   digitalWrite(ledBlue, HIGH); 
   delay(500);
   
   //pisca a cor verde
   digitalWrite(ledGreen, LOW);
   delay(500);
   
   //desliga  
   digitalWrite(ledGreen, HIGH);  
   

 
   
   dht.begin();
}

void loop() {
    float humidity = dht.readHumidity();
    float temperatureCelsius =dht.readTemperature();
  
    if (isnan(humidity) || isnan(temperatureCelsius)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("humidity : "); 
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("temperature : "); 
    Serial.print(temperatureCelsius);
    Serial.println("  Celsius ");
  
  
  // EOs dados de tabela de humidity foram coletados
  //do site http://www.ccohs.ca/oshanswers/phys_agents/humidex.html
  // obedecendo as constatateis de temperatureCelsius humidity, ideal para humanos 
      
    if(temperatureCelsius >= 15 && temperatureCelsius < 21){
          
        if(humidity < 40){
              digitalWrite(ledRed, LOW); 
              digitalWrite(ledGreen, HIGH);
              digitalWrite(ledBlue, HIGH);
              digitalWrite(canalRele, LOW);
         }
      
        if(humidity >= 40 && humidity <= 70){
              digitalWrite(ledRed, HIGH);
              digitalWrite(ledGreen, LOW);
              digitalWrite(ledBlue, HIGH);
            
              if(humidity >= 40 && humidity <= 55){ 
                digitalWrite(canalRele, LOW);
              }
        }
           
        if(humidity > 67){
              digitalWrite(ledRed, HIGH);
              digitalWrite(ledGreen, HIGH);
              digitalWrite(ledBlue, LOW);
              
              digitalWrite(canalRele, HIGH);
          }
    }       
           
     if(temperatureCelsius >= 21 && temperatureCelsius < 22){
          
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 70){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             if(humidity >= 40 && humidity <= 55){
               digitalWrite(canalRele, LOW);
             }
           }
           
           if(humidity > 67){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
     
     
      if(temperatureCelsius >= 22 && temperatureCelsius < 23){
          
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 70){
             digitalWrite(ledGreen, LOW);
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             if(humidity >= 40 && humidity <= 55){
               digitalWrite(canalRele, LOW);
             }

           }
           
           if(humidity > 67){
             digitalWrite(ledBlue, LOW);
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
          }
     }
     
     
     
      if(temperatureCelsius >= 23 && temperatureCelsius < 24){
          
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 70){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             if(humidity >= 40 && humidity <= 55){
               digitalWrite(canalRele, LOW);
             }
           }
           
           if(humidity > 67){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
            ;
         
           }
     }
     
     
      if(temperatureCelsius >= 24 && temperatureCelsius < 25){
          
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 65){
             
                digitalWrite(ledGreen, LOW);
             
               digitalWrite(ledRed, HIGH);
               digitalWrite(ledBlue, HIGH);
        
             
               if(humidity >= 40 && humidity <= 55){
                     digitalWrite(canalRele, LOW);
               }
            
           }
           
           if(humidity > 62){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
     
     
     
     if(temperatureCelsius >= 25 && temperatureCelsius <26){
         
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 55){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
           
              if(humidity >= 40 && humidity <= 46){
               digitalWrite(canalRele, LOW);
              }
           }
           
           if(humidity > 52){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
     
     
    
     
 
    
     if(temperatureCelsius >=26 && temperatureCelsius < 27){
     
       
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 50){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             if(humidity >= 40 && humidity <= 45){
               digitalWrite(canalRele, LOW);
             }
           }
           
           if(humidity > 45){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
     
     
     
     if(temperatureCelsius >= 27 && temperatureCelsius < 28){
        
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 45){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             if(humidity >= 40 && humidity <= 42){
               digitalWrite(canalRele, LOW);
             }
           }
           
           if(humidity > 45){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
     
     
     
     
     if(temperatureCelsius >= 28){
          
        if(humidity < 40){
             digitalWrite(ledRed, LOW); 
             digitalWrite(ledGreen, HIGH);
             digitalWrite(ledBlue, HIGH);
             
              digitalWrite(canalRele, LOW);
         }
         
           if(humidity >= 40 && humidity <= 43){
             digitalWrite(ledGreen, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledBlue, HIGH);
             
             digitalWrite(canalRele, LOW);
           }
           
           if(humidity > 43){
             digitalWrite(ledBlue, LOW);
             
             digitalWrite(ledRed, HIGH);
             digitalWrite(ledGreen, HIGH);
             
             digitalWrite(canalRele, HIGH);
             
      
         
           }
     }
  
  delay(30000);
}




