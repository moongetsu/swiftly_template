#include <swiftly/swiftly.h> // Base Include
#include <swiftly/server.h> // Server Include

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
}

void OnPluginStart()
{
    
}

void OnPluginStop()
{
    
}

const char *GetPluginName() // Plugin Name
{
    return "PLUGIN_NAME"; // This is an example, you can put here whatever you want
}

const char *GetPluginAuthor() // Plugin Author
{
    return "PLUGIN_AUTHOR"; // This is an example, you can put here whatever you want
}

const char *GetPluginVersion() // Plugin Version
{
    return "PLUGIN_VERSION"; // This is an example, you can put here whatever you want
}

const char *GetPluginWebsite() // Plugin Website
{
    return "PLUGIN_WEBSITE"; // This is an example, you can put here whatever you want
}