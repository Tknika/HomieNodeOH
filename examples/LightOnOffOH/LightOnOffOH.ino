#include <Homie.h>
#include <HomieNodeOH.h>

const int PIN_RELAY = 5;

// class      name    nodeId     nodeType    itemtype settable
HomieNodeOH lightNode("light", "ESH:Switch", "Switch", true);

bool lightOnHandler(const HomieRange& range, const String& value) {
  if (value != "true" && value != "false") return false;

  bool on = (value == "true");
  digitalWrite(PIN_RELAY, on ? HIGH : LOW);
  lightNode.setProperty("value").send(value);
  Homie.getLogger() << "Light is " << (on ? "on" : "off") << endl;

  return true;
}

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, LOW);

  Homie_setFirmware("awesome-relay", "1.0.0");

  lightNode.advertise("value").settable(lightOnHandler);

  Homie.setup();
}

void loop() {
  Homie.loop();
}
