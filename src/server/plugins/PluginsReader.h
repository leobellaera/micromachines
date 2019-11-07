//
// Created by eliana on 7/11/19.
//

#ifndef MICROMACHINES_PLUGINSREADER_H
#define MICROMACHINES_PLUGINSREADER_H

#include <dirent.h>
#include <cstdio>
#include <iostream>
#include <map>

class PluginsReader {
private:
    std::map<std::string, struct dirent> files;
public:
    void dirReader();
};


#endif //MICROMACHINES_PLUGINSREADER_H
