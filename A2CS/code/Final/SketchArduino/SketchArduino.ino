//
//  io.c
//  IOT
//
//  Created by Ian Ducrot  & Aurélien on 16/03/2019.
//  Copyright © 2019 Ian DUCROT. All rights reserved.
//



#include <Wire.h>
#include "MMA7660.h"
#include "DHT.h"
#include "MutichannelGasSensor.h"
#include <rgb_lcd.h>

#define DHTPIN A4           // PIN TEMPHUM
#define DHTTYPE DHT11  

int MoPin = 4; //Vibration

MMA7660 accelemeter;
DHT dht(DHTPIN, DHTTYPE);
unsigned long sampletime_ms = 100;         // ADJUST TIME
unsigned long duration;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;
String end = "END";
// GAS, ACCELEROMETER, HEARTRATE, LCD MONITOR: IIC
rgb_lcd lcd;

void setup()
{
  Serial.begin(115200);     // BAUD 115200 SERIAL MONITOR

  //Accelerometer
  accelemeter.init();  
  //TempHum 
  dht.begin();
  //Gas 
  gas.begin(0x04);          // PIN GAS : I2C address 0x04
  gas.powerOn();
  //LCD
  lcd.begin(16,2);
  lcd.clear();
  lcd.setRGB(0,255,0);
  //Vibration
  pinMode (MoPin, OUTPUT);

}

void loop()
{
  lcd.setCursor(0,0);

  Serial.println("<");      // start marker

  //Accelerometer
  Serial.println("Accelerometer");
  int8_t x;
  int8_t y;
  int8_t z;
  char temp[5];
  char humidity[5];
  accelemeter.getXYZ(&x,&y,&z);
  Serial.print("x = ");
  Serial.println(x); 
  Serial.print("y = ");
  Serial.println(y);   
  Serial.print("z = ");
  Serial.println(z);

  //TempHum
  Serial.println("Temp&Humidity");
  float t = dht.readTemperature();
  float h = dht.readHumidity();                                                                   

  //Gas
  Serial.println("Gas");
  float c;
  float tab[7];

  c = gas.measure_NH3();
  tab[0] = c;
  gasResults(c, (char *) "NH3");

  c = gas.measure_CO();
  tab[1] = c;
  gasResults(c, (char *) "CO");

  c = gas.measure_NO2();
  tab[2] = c;
  gasResults(c, (char *) "NO2");

  c = gas.measure_C3H8();
  tab[3] = c;
  gasResults(c, (char *) "C3H8");

  c = gas.measure_CH4();
  tab[4] = c;
  gasResults(c, (char *) "CH4");

  c = gas.measure_H2();
  tab[5] = c;
  gasResults(c, (char *) "H2");

  c = gas.measure_C2H5OH();
  tab[6] = c;
  gasResults(c, (char *) "C2H5OH");

  if (tab[0] >= 35.00 || tab[1] >= 50.00 || tab[2] >= 3.00 || tab[3] >= 10000.00 || tab[4] >= 3000.00 || tab[5] >= 4100.00 || tab[6] >= 1000.00) {
    lcd.setRGB(255,165,0);
    lcd.clear();
    lcd.print("!!  GAZ % ABOVE  !!");
    lcd.setCursor(0, 1);
    lcd.print("!!  THE LIMITS !!");
    digitalWrite(MoPin, HIGH);
    delay(1000);
    digitalWrite(MoPin, LOW);
    delay(1000);
  }
  else
  {
    lcd.setRGB(0,255,0);
    lcd.clear();
    lcd.print("       GAZ      ");
    lcd.setCursor(0, 1);
    lcd.print("       OK       ");
    delay(3000);

    if (isnan(t)) {
      Serial.println("Failed to read from DHT");
    } 
    else { 
      Serial.print(t);
      lcd.clear();

      Serial.println(" *C");
      lcd.print("Room Temp:");
      lcd.setCursor(12, 0);
      lcd.print( dtostrf(t, 5, 2,temp));
      lcd.setCursor(14,0);
      lcd.print("'C");



      Serial.print(h);
      lcd.setCursor(0, 1);
      lcd.print("Humidity:");
      lcd.setCursor(10, 1);
      lcd.print( dtostrf(h, 5, 2,humidity));
      lcd.setCursor(15,1);
      lcd.print("%");

      Serial.println();
      delay(3000);

      //lcd.print("Temp : %f / Hum : %f", t, h );

    }

  }

  Serial.print(end);
  Serial.println();
  delay(sampletime_ms);
}

void gasResults(float c, char gasName[]){
  //Serial.print("The concentration of ");
  Serial.print(gasName);
  Serial.print(": ");
  if(c>=0) Serial.print(c);
  else Serial.print("invalid");
  Serial.println(" ppm");
}

