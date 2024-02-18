//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_CONSOLE_H
#define TOPAZLANG_CONSOLE_H

#include <string>
#include <iostream>
#include <atomic>

struct Console {
    static void progressBar(std::atomic<float>&, int);
};


#endif //TOPAZLANG_CONSOLE_H
