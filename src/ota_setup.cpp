#include <WebServer.h>
#include <ElegantOTA.h>

// extern WebServer server_ota;
WebServer server_ota(85);

void ota_setup() {
  server_ota.on("/", []() {
    server_ota.send(200, "text/plain", "Hi! Enerinno.");
  });

  ElegantOTA.begin(&server_ota);    // Start ElegantOTA
  server_ota.begin();
  Serial.println("HTTP server started");
}

void ota_loop(){
    server_ota.handleClient();
}