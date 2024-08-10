# ESP32 Servo Control via Web Interface

This task uses an ESP32 D1 Mini to control a servo motor through a web interface. The web page features a slider to adjust the angle of the servo, and the ESP32 handles incoming requests to set the servo position accordingly.


| User Interface | Execute  |
| -- | -- |
| <img src="https://github.com/user-attachments/assets/92b36290-759f-473b-b6a4-56ed300a5180" width="300" /> |   <img src="https://github.com/user-attachments/assets/bd2e47cf-54c6-4d0e-87c1-98c2ac8470ce" width="300" /> |


## Components

- ESP32 D1 Mini
- Servo Motor
- Jumper Wires

## Circuit Diagram

1. **Servo Motor Connections:**
   - **VCC (Red Wire)**: Connect to `3V3` on the ESP32 D1 Mini.
   - **GND (Black/Brown Wire)**: Connect to `GND` on the ESP32 D1 Mini.
   - **Signal (Yellow/White Wire)**: Connect to GPIO pin `18` on the ESP32 D1 Mini.

## Software Setup
1. **Arduino IDE Setup:**
   - https://youtu.be/ZwSQzpiaszo?si=VVGRimdC3EXavGOd
   - https://github.com/me-no-dev/arduino-esp32fs-plugin
   - Add the ESP32 board support:
     1. Go to `File` > `Preferences`.
     2. In the `Additional Board Manager URLs` field, add the following URL:
        
        ```
        https://dl.espressif.com/dl/package_esp32_index.json
        ```
     3. Go to `Tools` > `Board` > `Boards Manager`.
     4. Search for "ESP32" and install it.

3. **Install Libraries:**
   - Go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Install the following libraries:
     - `ESP32Servo` (for servo control)
     - `WebServer` (for serving web pages)
     - `ESPAsyncWebServer`
     - `AsyncTCP`

4. **Upload the Sketch:**
   - Open the Arduino IDE.
   - Connect your ESP32 D1 Mini to your computer.
   - Select `Tools` > `Board` > `WEMOS D1 MINI ESP32`.
   - Select the appropriate port under `Tools` > `Port`.
   - Open the `webServer.ino` sketch and upload it to the ESP32.

5. **Web Interface**

1. Once the ESP32 is connected to your WiFi network, open the Serial Monitor to get the IP address assigned to your ESP32.
2. Enter this IP address into your web browser to access the control interface.
3. Use the slider on the web page to adjust the angle of the servo.
