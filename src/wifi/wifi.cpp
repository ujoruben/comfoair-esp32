#include "../secrets.h"
#include <WiFi.h>
#include "wifi.h"

namespace comfoair {
  void WiFi::setup() {
      Serial.println();
      delay(5000);
      Serial.print("Connecting to ");
      Serial.println(WIFI_SSID);
      ::WiFi.disconnect(true, true);
      esp_log_level_set("wifi", ESP_LOG_VERBOSE);
      esp_log_level_set("wpa", ESP_LOG_VERBOSE);
      delay(200);
      ::WiFi.mode(WIFI_STA);
      delay(5000);
      ::WiFi.begin(WIFI_SSID, WIFI_PASS);
      ::WiFi.setAutoReconnect(true);
      while (::WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.println(::WiFi.status());
      }
      Serial.println("");
      Serial.println("WiFi Connected. IP: ");
      Serial.println(::WiFi.localIP());
  }

  void WiFi::loop() {
      //  NOthing to do!
  }
} 
