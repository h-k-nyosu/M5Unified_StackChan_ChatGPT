#include "my_http_handlers/my_http_handlers.h"


void handleRoot() {
  server.send(200, "text/plain", "hello from m5stack!");
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
//  server.send(404, "text/plain", message);
  server.send(404, "text/html", String(HEAD) + String("<body>") + message + String("</body>"));
}

void handle_speech() {
  String message = server.arg("say");
//  message = message + "\n";
  Serial.println(message);
  ////////////////////////////////////////
  // 音声の発声
  ////////////////////////////////////////
  avatar.setExpression(Expression::Happy);
  VoiceText_tts((char*)message.c_str(),tts_parms2);
  avatar.setExpression(Expression::Neutral);
  server.send(200, "text/plain", String("OK"));
}

void handle_chat() {
  static String response = "";
  String text = server.arg("text");
  String json_string = "{\"model\": \"gpt-3.5-turbo\",\"messages\": [{\"role\": \"user\", \"content\": \"" + text + "\"}]}";
  response = chatGpt(json_string);
  speech_text = response;
  server.send(200, "text/html", String(HEAD)+String("<body>")+response+String("</body>"));
}

void handle_face() {
  String expression = server.arg("expression");
  expression = expression + "\n";
  Serial.println(expression);
  switch (expression.toInt())
  {
    case 0: avatar.setExpression(Expression::Neutral); break;
    case 1: avatar.setExpression(Expression::Happy); break;
    case 2: avatar.setExpression(Expression::Sleepy); break;
    case 3: avatar.setExpression(Expression::Doubt); break;
    case 4: avatar.setExpression(Expression::Sad); break;
    case 5: avatar.setExpression(Expression::Angry); break;  
  } 
  server.send(200, "text/plain", String("OK"));
}