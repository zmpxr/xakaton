// библиотека для работы с датчиком качества воздуха CCS811
#include "Adafruit_CCS811.h"
 
// создаём объект для работы с датчиком
Adafruit_CCS811 ccs;
 
void setup() {
 // открываем Serial-порт
 Serial.begin(9600);
 Serial.println("Amperka CCS811 test...");
 // если датчик не прошел проверку, дальше не идем и крутимся в цикле
 if(!ccs.begin()){
   Serial.println("Failed to start sensor! Please check your wiring.");
   while(1);
 }
}
 
void loop() {
 // если пришли новые данные
 if(ccs.available()) {
   // считываем данные
   if(!ccs.readData()) {
     // выводим в Serial-порт показания концентрации CO2
     // и количество летучих органических веществ
     Serial.print("CO2: ");
     Serial.print(ccs.geteCO2());
     Serial.print("ppm, TVOC: ");
     Serial.println(ccs.getTVOC());
   } else {
     Serial.println("ERROR...");
     while(1);
   }
 }
 delay(500);
}
