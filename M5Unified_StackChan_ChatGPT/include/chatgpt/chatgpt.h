#ifndef CHATGPT_H
#define CHATGPT_H

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <Avatar.h>
using namespace m5avatar;

extern Avatar avatar;

String chatGpt(String json_string);
String https_post_json(const char*, const char*, const char*);

#endif