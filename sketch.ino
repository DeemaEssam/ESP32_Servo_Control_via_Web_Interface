#include <WiFi.h>
#include <ESP32Servo.h>
#include <FS.h>
#include <SPIFFS.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = ""; 


WebServer server(80);

Servo myservo;  // Create a servo object
int servoPin = 18;  // GPIO pin for the servo
int servoPosition = 90;  // Initial position of the servo

void handleRoot() {
  File file = SPIFFS.open("/slider.html", "r");
  if (file) {
    server.streamFile(file, "text/html");
    file.close();
  } else {
    server.send(404, "text/plain", "File Not Found");
  }
}

void handleServoControl() {
  if (server.hasArg("value")) {
    servoPosition = server.arg("value").toInt();
    myservo.write(servoPosition);
    server.send(200, "text/plain", "Servo angle set to: " + String(servoPosition));
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}

void setup() {
  Serial.begin(115200);

  myservo.attach(servoPin);  // Attach the servo to GPIO 13

  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/setAngle", handleServoControl);
  server.begin();
}

void loop() {
  server.handleClient();  // Handle incoming client requests
}
