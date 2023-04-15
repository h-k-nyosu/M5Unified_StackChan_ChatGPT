#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include <ESPmDNS.h>
#include <ESP32WebServer.h>

extern ESP32WebServer server;

void wifiManagerSetup();
void wifiManagerLoop();

#endif