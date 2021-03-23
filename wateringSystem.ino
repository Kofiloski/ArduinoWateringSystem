#include <dht.h>

dht DHT;
#define DHT11_PIN 7
#define WATER_PUMP 9
#define MODE 4
#define LED 8  // Pump working indicator

#define HUMIDITY_THRESHOLD 20
#define PUMP_FREQUENCY 1000
#define PUMP_ENABLE_TIME 1000 // Time to be enabled (in ms)

int mode;
int humidityRead;
int temperatureRead;
long lastTimeActive;
bool pumpEnabled;
int valueFromSensor;

void setup() {
  pinMode(WATER_PUMP, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(MODE, INPUT);
  digitalWrite(MODE, HIGH);  // Starting in time mode
  disablePump();
}

void loop() {
  if (mode == HIGH) {
    if (!pumpEnabled && millis() > lastTimeActive + PUMP_FREQUENCY) {
      enablePump();
      lastTimeActive = millis();
    }
    if (pumpEnabled && millis() > lastTimeActive + PUMP_ENABLE_TIME) {
      disablePump();
      lastTimeActive = millis();
    }
  } else if (mode == LOW) {
    valueFromSensor = DHT.read11(DHT11_PIN);
    temperatureRead = DHT.temperature;
    humidityRead = DHT.humidity;

    if (humidityRead < HUMIDITY_THRESHOLD && temperatureRead > 25) {
      if (!pumpEnabled) enablePump();
    } else {
      if (pumpEnabled) disablePump();
    }
  }

  delay(1000);
}

void enablePump() {
    digitalWrite(WATER_PUMP, HIGH);
    digitalWrite(LED, HIGH);
    pumpEnabled = true;
}

void disablePump() {
  digitalWrite(WATER_PUMP, LOW);
  digitalWrite(LED, LOW);
  pumpEnabled = false;
}
