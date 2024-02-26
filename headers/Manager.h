//
// Created by leny on 26.02.24.
//

#ifndef TOPAZLANG_MANAGER_H
#define TOPAZLANG_MANAGER_H

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct Executable {
    std::vector<std::string> files;
    std::string name;
};

struct Manager {
    static void parseSettings();

    static std::unordered_map<std::string, std::string> parameters;
    static std::vector<Executable> executables;
    static std::unordered_map<std::string, std::string> constantes;

    static inline constinit std::string settingsFile = "settings.tpzc";
};

#endif //TOPAZLANG_MANAGER_H
