/*
 Name:    Velleman - DIGITALE TEMPERATUUR- EN VOCHTSENSOR DHT11
 Created: 26-01-2021
 Author:  W. de Vaal
 Website: http://www.wdevaal.nl

    Components used:
     Velleman - WPSE311
*/

// include the library code
#include "DHT.h"


// define varialble
#define DHTTYPE DHT11


// define pins
int DHTPin = 7;


// define objects
DHT dht(DHTPin, DHTTYPE);


// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(9600);
    dht.begin();
}


// the loop function runs over and over again until power down or reset
void loop() {
    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("�C "));
    Serial.print(f);
    Serial.print(F("�F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("�C "));
    Serial.print(hif);
    Serial.println(F("�F"));
}