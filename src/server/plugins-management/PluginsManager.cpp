//
// Created by eliana on 7/11/19.
//

#include "PluginsManager.h"
#include "PluginHandler.h"
#include "PluginHandlerException.h"

#define DIRECTORY "../src/server/plugins-management/plugins/"
#define EXTENSION "so"

PluginsManager::PluginsManager():
    finished(false) {}

void PluginsManager::run() {
    while (!finished) {
        readPluginsDirectory();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void PluginsManager::readPluginsDirectory() {
    std::unique_lock<std::mutex> lck(mutex);
    DIR* dir;
    struct dirent* file;
    dir = opendir(DIRECTORY);
    if (dir != nullptr) {
        while ((file = readdir(dir)) != nullptr) {
            std::string fileName = std::string(file->d_name);
            if(fileName.substr(fileName.find_last_of('.') + 1) == EXTENSION
                    && plugins.count(fileName) == 0) {
                try {
                    std::string path = DIRECTORY + fileName;
                    auto handler = new PluginHandler(path.c_str());
                    Plugin* plugin = handler->create();
                    handlers.push_back(handler);
                    plugins.emplace(fileName, plugin);
                } catch (const PluginHandlerException& e) {
                    continue;
                }
            }
        }
        closedir(dir);
    }
}

void PluginsManager::applyPlugins() {
    std::unique_lock<std::mutex> lck(mutex);
    for (auto & plugin : plugins) {
        plugin.second->updateModel();
    }
}

void PluginsManager::stop() {
    finished = true;
}

PluginsManager::~PluginsManager() {
    for (auto & plugin : plugins) {
        delete plugin.second;
    }
    for (auto & handler : handlers) {
        delete handler;
    }
}