#include <SoftwareSerial.h>

#define BLE_RX_PIN	10
#define BLE_TX_PIN	11

SoftwareSerial BLE_Serial(BLE_RX_PIN, BLE_TX_PIN);

void setup() {
    Serial.begin(9600);
    Serial.println("Hello, HM-10!");
    BLE_Serial.begin(9600);
}

void loop() {
    while (BTSerial.available()) { // Bluetooth -> Serial
        byte data = BTSerial.read();
        Serial.write(data);
    }
    while (Serial.available()) { // Serial -> Bluetooth
        byte data = Serial.read();
        BTSerial.write(data);
    }
}
