#include "application.h"

static const uint32_t interval = 1000;
static uint32_t lastMillis = 0;

SYSTEM_THREAD(ENABLED);

void setup() {
    // Serial is always enabled by default, but here we need to call it so that HAL can allocate buffers for us.
    // In 0.6.0 the buffers are allocated in user-space
    Serial.begin(9600);
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
