// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
   class PluginInterface 
   {
   public:
      virtual ~PluginInterface() = default;
      virtual void execute() = 0; 
   };

   class Plugins 
   {
   private:
      std::vector<void*> loadedPlugins;  

   #ifdef _WIN32
      typedef PluginInterface* (*CreatePlugin)(); 
   #else
      typedef PluginInterface* (*create_plugin)();  
   #endif

   public:
      Plugins() = default;
      ~Plugins() 
      {
        for (auto plugin : loadedPlugins) 
	{
        #ifdef _WIN32
            FreeLibrary((HMODULE)plugin);
        #else
            dlclose(plugin);
        #endif
        }
      }

      bool LoadPlugin(const std::wstring& pluginPath) 
      {
        void* pluginHandle = nullptr;

        #ifdef _WIN32
        pluginHandle = LoadLibraryW(pluginPath.c_str());
        if (!pluginHandle) 
	{
            std::cerr << "Plugin loading error: " << GetLastError() << "\n";
            return false;
        }

        CreatePlugin createPlugin = (CreatePlugin)GetProcAddress((HMODULE)pluginHandle, "createPlugin");
        if (!createPlugin) 
	{
            std::cerr << "The createPlugin() function could not be found in the plugin\n";
            return false;
        }
        #else
        pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
        if (!pluginHandle) 
	{
            std::cerr << "Plugin loading error: " << dlerror() << "\n";
            return false;
        }
        create_plugin createPlugin = (create_plugin)dlsym(pluginHandle, "createPlugin");
        if (!createPlugin) {
            std::cerr << "the createPlugin() function could not be found in the plugin\n";
            return false;
        }
        #endif

        PluginInterface* plugin = createPlugin();
        if (plugin) 
	{
            loadedPlugins.push_back(pluginHandle);
            plugin->execute(); 
            return true;
        }
        else 
	{
            std::cerr << "The plugin could not be created\n";
            return false;
        }
      }
  };
}
