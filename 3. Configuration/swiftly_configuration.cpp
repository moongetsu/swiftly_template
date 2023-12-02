#include <swiftly/swiftly.h> // Base Include
#include <swiftly/server.h> // Server Include
#include <swiftly/commands.h> // Commands Include
#include <swiftly/configuration.h> // Configuration Include

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Commands *commands = nullptr;
Configuration *config = nullptr;


void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
    commands = new Commands(pluginName);
    config = new Configuration();
}

void OnPluginStart()
{
    commands->Register("numberconfig", reinterpret_cast<void*>(&Number_Command));
    commands->Register("textconfig", reinterpret_cast<void*>(&Text_Command));
    commands->Register("listconfig", reinterpret_cast<void*>(&List_Command));
}

void Number_Command()
{
    print("This command will send a number from the config! \n");
    print("Number: %d \n", config->Fetch<int>("configtemplate.number"));
}

void Text_Command()
{
    print("This command will send a text from the config! \n");
    print("Text: %s \n", config->Fetch<const char*>("configtemplate.text"));
}

void List_Command()
{
    print("This command will send a list from the config! \n");
    print("Text1: %s \n", config->Fetch<const char*>("configtemplate.list[0]"));
    print("Text2: %s \n", config->Fetch<const char*>("configtemplate.list[1]"));
    print("Text3: %s \n", config->Fetch<const char*>("configtemplate.list[2]"));
}

void OnPluginStop()
{

}