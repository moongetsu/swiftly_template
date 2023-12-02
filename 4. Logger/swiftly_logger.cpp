#include <swiftly/swiftly.h> // Base Include
#include <swiftly/server.h> // Server Include
#include <swiftly/logger.h> // Loggers Include

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Logger *logger = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    server = new Server();
    g_playerManager = new PlayerManager();
    logger = new Logger(mainFilePath, pluginName);
}

void OnPluginStart()
{
    logger->Write(LOGLEVEL_DEBUG, "This is a Debug Log!");
    logger->Write(LOGLEVEL_WARNING, "This is a Warning Log!");
    logger->Write(LOGLEVEL_ERROR, "This is an Error Log!");
    logger->Write(LOGLEVEL_COMMON, "This is a Common Log!");
}

void OnPluginStop()
{
    
}