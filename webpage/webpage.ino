#include <WiFi.h>
#include <WebServer.h>  // Include the WebServer library

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Create a web server object on port 80
WebServer server(80);

// Pin where the relay is connected
const int relayPin = 5;  // Adjust to your relay pin

void handleRoot() {
  // HTML code for the web interface
  String htmlPage = "<html><body>";
  htmlPage += "<h1>Relay Control</h1>";
  htmlPage += "<button onclick=\"location.href='/on'\" style=\"font-size:24px\">ON</button>";
  htmlPage += "<button onclick=\"location.href='/off'\" style=\"font-size:24px; margin-left:20px;\">OFF</button>";
  htmlPage += "</body></html>";
  
  // Send the web page
  server.send(200, "text/html", htmlPage);
}

void handleRelayOn() {
  digitalWrite(relayPin, HIGH);  // Turn the relay ON
  server.send(200, "text/html", "<html><body><h1>Relay ON</h1><a href='/'>Go Back</a></body></html>");
}

void handleRelayOff() {
  digitalWrite(relayPin, LOW);   // Turn the relay OFF
  server.send(200, "text/html", "<html><body><h1>Relay OFF</h1><a href='/'>Go Back</a></body></html>");
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Initialize the relay pin as OUTPUT
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Ensure the relay starts OFF

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define routes
  server.on("/", handleRoot);  // Route for the home page
  server.on("/on", handleRelayOn);   // Route for turning relay ON
  server.on("/off", handleRelayOff); // Route for turning relay OFF

  // Start the server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}
