#include "application.h"

static const uint32_t interval = 1000;
static uint32_t lastMillis = 0;

SYSTEM_THREAD(ENABLED);
USBSERIAL1_ENABLE();

void setup() {
    // Serial is always enabled by default
    // Serial.begin();
    Serial.end();

    // USBSerial1 enabled by USBSERIAL1_ENABLE() macro to avoid USB reenumeration
    // USBSerial1.begin();
}

void loop() {
    uint32_t ts = millis();
    if ((ts - lastMillis) >= interval) {
        USBSerial1.printf("USBSerial1 millis=%d\r\n", ts);
        lastMillis = millis();
    }

    while(USBSerial1.available()) {
        USBSerial1.write(USBSerial1.read());
    }
}
