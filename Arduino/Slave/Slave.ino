#include <esp_now.h>
#include <WiFi.h>

// Pin where the relay is connected
const int relayPin = 5;  // Use the appropriate GPIO pin for your relay

// Structure to receive the label
typedef struct struct_message {
    char label[10];  // Adjust size as needed
} struct_message;

struct_message incomingData;

// Callback function when data is received via ESP-NOW
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingDataBytes, int len) {
    memcpy(&incomingData, incomingDataBytes, sizeof(incomingData));
    Serial.print("Received label: ");
    Serial.println(incomingData.label);

    // Control the relay based on the received label
    if (strcmp(incomingData.label, "ON") == 0) {
        digitalWrite(relayPin, HIGH);  // Turn relay ON
        Serial.println("Relay is ON");
    } 
    else if (strcmp(incomingData.label, "OFF") == 0) {
        digitalWrite(relayPin, LOW);   // Turn relay OFF
        Serial.println("Relay is OFF");
    }
}


void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Initialize the relay pin
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW);  // Ensure relay starts OFF

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(); // Disconnect from any AP

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register receive callback
    esp_now_register_recv_cb(OnDataRecv);

    Serial.println("ESP-NOW Receiver Initialized");
}

void loop() {
    // Do nothing, waiting for incoming ESP-NOW messages
}
