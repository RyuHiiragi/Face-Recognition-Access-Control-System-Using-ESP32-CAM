#include "esp_camera.h"
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Relay pin
#define RELAY_PIN 5

// Camera model
#define CAMERA_MODEL_AI_THINKER

// Face recognition variables
bool isAuthenticated = false;

void setup() {
  Serial.begin(115200);

  // Initialize the camera
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  if (psramFound()) {
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // Initialize the camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.println("Camera init failed");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wi-Fi connected");

  // Set relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Initially off
}

void loop() {
  // Capture an image
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  // Perform face recognition (replace with your recognition logic)
  isAuthenticated = recognizeFace(fb->buf, fb->len);

  // Control the relay based on recognition result
  if (isAuthenticated) {
    Serial.println("Access Granted");
    digitalWrite(RELAY_PIN, HIGH); // Unlock the door
    delay(5000); // Keep the door unlocked for 5 seconds
    digitalWrite(RELAY_PIN, LOW); // Lock the door again
  } else {
    Serial.println("Access Denied");
  }

  // Return the frame buffer back to the driver
  esp_camera_fb_return(fb);
  delay(1000); // Adjust loop speed
}

bool recognizeFace(uint8_t *imageBuffer, size_t imageSize) {
  // Placeholder for face recognition logic
  // You can use libraries like TensorFlow Lite or OpenCV for actual recognition
  // For now, return true for testing purposes
  return true;
}
