#include "wifi_manager/wifi_manager.h"
#include "my_http_handlers/my_http_handlers.h"
#include "config/config.hpp"

ESP32WebServer server(80);

void wifiManagerSetup()
{
  // Wi-Fi接続、Webサーバー、mDNS関連のセットアップコード
  server.on("/", handleRoot);
  server.on("/inline", [](){ server.send(200, "text/plain", "this works as well"); });
  server.on("/speech", handle_speech);
  server.on("/face", handle_face);
  server.on("/chat", handle_chat);
  server.onNotFound(handleNotFound);
  server.begin();
}

void wifiManagerLoop()
{
  server.handleClient();
}