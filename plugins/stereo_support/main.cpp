#include "core/plugin.h"
#include "logger.h"
#include "core/module.h"

#include "stereo/module_stereo_instruments.h"

class StereoSupport : public satdump::Plugin
{
public:
    std::string getID()
    {
        return "stereo_support";
    }

    void init()
    {
        satdump::eventBus->register_handler<RegisterModulesEvent>(registerPluginsHandler);
    }

    static void registerPluginsHandler(const RegisterModulesEvent &evt)
    {
        REGISTER_MODULE_EXTERNAL(evt.modules_registry, stereo::StereoInstrumentsDecoderModule);
    }
};

PLUGIN_LOADER(StereoSupport)