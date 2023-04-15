#ifndef VOICE_TEXT_TTS_H
#define VOICE_TEXT_TTS_H

#include <AudioOutput.h>
#include <AudioFileSourceBuffer.h>
#include <AudioGeneratorMP3.h>
#include "AudioFileSourceVoiceTextStream/AudioFileSourceVoiceTextStream.h"
#include "AudioOutputM5Speaker/AudioOutputM5Speaker.h"

extern const int preallocateBufferSize;
extern uint8_t *preallocateBuffer;
extern AudioOutputM5Speaker out;

extern AudioGeneratorMP3 *mp3;
extern AudioFileSourceVoiceTextStream *file;
extern AudioFileSourceBuffer *buff;

void MDCallback(void *cbData, const char *type, bool isUnicode, const char *string);
void StatusCallback(void *cbData, int code, const char *string);
void VoiceText_tts(char *text,char *tts_parms);

#endif