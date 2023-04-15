#include "AudioOutputM5Speaker/AudioOutputM5Speaker.h"

AudioOutputM5Speaker::AudioOutputM5Speaker(m5::Speaker_Class* m5sound, uint8_t virtual_sound_channel)
    : _m5sound{m5sound},
      _virtual_ch{virtual_sound_channel},
      _tri_buffer_index{0},
      _tri_index{0},
      _update_count{0}
{
}

AudioOutputM5Speaker::~AudioOutputM5Speaker(void)
{
}

bool AudioOutputM5Speaker::begin(void)
{
    return true;
}

bool AudioOutputM5Speaker::ConsumeSample(int16_t sample[2])
{
    if (_tri_buffer_index < tri_buf_size)
    {
        _tri_buffer[_tri_index][_tri_buffer_index] = sample[0];
        _tri_buffer[_tri_index][_tri_buffer_index + 1] = sample[1];
        _tri_buffer_index += 2;

        return true;
    }

    flush();
    return false;
}

void AudioOutputM5Speaker::flush(void)
{
    if (_tri_buffer_index)
    {
        _m5sound->playRaw(_tri_buffer[_tri_index], _tri_buffer_index, hertz, true, 1, _virtual_ch);
        _tri_index = _tri_index < 2 ? _tri_index + 1 : 0;
        _tri_buffer_index = 0;
        ++_update_count;
    }
}

bool AudioOutputM5Speaker::stop(void)
{
    flush();
    _m5sound->stop(_virtual_ch);
    for (size_t i = 0; i < 3; ++i)
    {
        memset(_tri_buffer[i], 0, tri_buf_size * sizeof(int16_t));
    }
    ++_update_count;
    return true;
}

const int16_t* AudioOutputM5Speaker::getBuffer(void) const
{
    return _tri_buffer[(_tri_index + 2) % 3];
}

const uint32_t AudioOutputM5Speaker::getUpdateCount(void) const
{
    return _update_count;
}