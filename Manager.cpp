//
// Created by leny on 26.02.24.
//

#include "Manager.h"

void Manager::parseSettings() {
    std::ifstream file(settingsFile);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file.");
    }


}
