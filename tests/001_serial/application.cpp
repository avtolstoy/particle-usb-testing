#include "application.h"

static const uint32_t interval = 1000;
static uint32_t lastMillis = 0;

SYSTEM_THREAD(ENABLED);

void setup() {
    // Serial is always enabled by default
    // Serial.begin();
}

void loop() {
    uint32_t ts = millis();
    if ((ts - lastMillis) >= interval) {
        Serial.printf("Serial millis=%d\r\n", ts);
        lastMillis = millis();
    }

    while(Serial.available()) {
        Serial.write(Serial.read());
    }
}
