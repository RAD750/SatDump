#include "core/plugin.h"
#include "logger.h"
#include "portaudio_sink.h"

class PortAudioAudioSupport : public satdump::Plugin
{
public:
    std::string getID()
    {
        return "rtaudio_audio_sink";
    }

    void init()
    {
        satdump::eventBus->register_handler<audio::RegisterAudioSinkEvent>(registerSinks);
    }

    static void registerSinks(const audio::RegisterAudioSinkEvent &evt)
    {
        evt.sink_registry.emplace(PortAudioSink::getID(), PortAudioSink::getInstance);
    }
};

PLUGIN_LOADER(PortAudioAudioSupport)