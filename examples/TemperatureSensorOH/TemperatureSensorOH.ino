#include <Homie.h>
#include <HomieNodeOH.h>

const int TEMPERATURE_INTERVAL = 300;

unsigned long lastTemperatureSent = 0;

// class          Name          nodeId          nodeType      itemtype  unit
HomieNodeOH temperatureNode("temperature", "ESH:Temperature", "Number", "ºC");

void loopHandler() {
  if (millis() - lastTemperatureSent >= TEMPERATURE_INTERVAL * 1000UL || lastTemperatureSent == 0) {
    float temperature = 22; // Fake temperature here, for the example
    Homie.getLogger() << "Temperature: " << temperature << " °C" << endl;
    temperatureNode.setProperty("value").send(String(temperature));
    lastTemperatureSent = millis();
  }
}

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;
  Homie_setFirmware("awesome-temperature", "1.0.0");
  Homie.setLoopFunction(loopHandler);

  Homie.setup();
}

void loop() {
  Homie.loop();
}
