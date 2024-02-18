//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_CONFIGMANAGER_H
#define TOPAZLANG_CONFIGMANAGER_H

#include <vector>
#include <string>

struct ConfigManager {
    static std::vector<std::string> getExecutables();

private:
    static std::vector<std::string> executables;
};


#endif //TOPAZLANG_CONFIGMANAGER_H
