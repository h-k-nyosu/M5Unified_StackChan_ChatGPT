#pragma once

#include <ESP32WebServer.h>
#include <Avatar.h>
using namespace m5avatar;

extern ESP32WebServer server;
extern Avatar avatar;
extern char *tts_parms2;
extern const char HEAD[];
extern String speech_text;
String chatGpt(String);
void VoiceText_tts(char*, char*);

void handleRoot();
void handleNotFound();
void handle_speech();
void handle_chat();
void handle_face();
