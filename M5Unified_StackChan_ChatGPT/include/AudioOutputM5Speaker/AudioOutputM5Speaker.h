#ifndef AUDIO_OUTPUT_M5_SPEAKER_H
#define AUDIO_OUTPUT_M5_SPEAKER_H

#include <AudioOutput.h>
#include <M5Unified.h>

class AudioOutputM5Speaker : public AudioOutput
{
  public:
    AudioOutputM5Speaker(m5::Speaker_Class* m5sound, uint8_t virtual_sound_channel = 0);
    virtual ~AudioOutputM5Speaker(void);

    virtual bool begin(void) override;
    virtual bool ConsumeSample(int16_t sample[2]) override;
    virtual void flush(void) override;
    virtual bool stop(void) override;

    const int16_t* getBuffer(void) const;
    const uint32_t getUpdateCount(void) const;

  protected:
    m5::Speaker_Class* _m5sound;
    uint8_t _virtual_ch;
    static constexpr size_t tri_buf_size = 640;
    int16_t _tri_buffer[3][tri_buf_size];
    size_t _tri_buffer_index;
    size_t _tri_index;
    size_t _update_count;

};

#endif  // AUDIO_OUTPUT_M5_SPEAKER_H